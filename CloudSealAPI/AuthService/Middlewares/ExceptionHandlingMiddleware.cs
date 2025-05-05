using AuthService.Exceptions;

namespace AuthService.Middlewares;
public class ExceptionHandlingMiddleware
{
    private readonly RequestDelegate _next;
    private readonly ILogger<ExceptionHandlingMiddleware> _logger;

    public ExceptionHandlingMiddleware(RequestDelegate next, ILogger<ExceptionHandlingMiddleware> logger)
    {
        _next = next;
        _logger = logger;
    }

    public async Task InvokeAsync(HttpContext context)
    {
        try
        {
            await _next(context); // call the next middleware in the pipeline
        } 
        catch (Exception ex)
        {
            context.Response.StatusCode = ex switch
            {
                InvalidCredentialsException => StatusCodes.Status401Unauthorized,
                UsernameTakenException => StatusCodes.Status409Conflict,
                NotFoundException => StatusCodes.Status404NotFound,
                ArgumentException => StatusCodes.Status400BadRequest,
                UnauthorizedAccessException => StatusCodes.Status401Unauthorized,
                _ => StatusCodes.Status500InternalServerError
            };

            context.Response.ContentType = "application/json";

            var error = new { error = ex.Message };
            await context.Response.WriteAsJsonAsync(error);
        }
    }
}
