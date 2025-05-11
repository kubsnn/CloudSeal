
using System.Security.Cryptography.X509Certificates;
using UserService.Exceptions;

namespace UserService.Middlewares;

public class ExceptionHandlingMiddleware
{
    private readonly RequestDelegate _next;
    private readonly ILogger<ExceptionHandlingMiddleware> _logger;

    public ExceptionHandlingMiddleware(RequestDelegate next, ILogger<ExceptionHandlingMiddleware> logger)
    {
        _next = next;
        _logger = logger;
    }
    public Task InvokeAsync(HttpContext context)
    {
        try
        {
            return _next(context);
        } catch (Exception ex)
        {
            context.Response.StatusCode = ex switch
            {
                InvalidCredentialsException => StatusCodes.Status401Unauthorized,
                ConflictException => StatusCodes.Status409Conflict,
                _ => StatusCodes.Status500InternalServerError
            };
            context.Response.ContentType = "application/json";
            var error = new { error = ex.Message };
            return context.Response.WriteAsJsonAsync(error);
        }
    }
}
