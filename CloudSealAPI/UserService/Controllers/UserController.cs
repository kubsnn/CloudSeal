using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.Security.Claims;
using UserService.Models;
using UserService.Services;

namespace UserService.Controllers
{
    [Authorize]
    [ApiController]
    [Route("api/v1/[controller]")]
    public class UserController : ControllerBase
    {
        private readonly IUserService _userService;
        private string? _userId => User.FindFirstValue(ClaimTypes.NameIdentifier);
        public UserController(IUserService userService)
        {
            _userService = userService;
        }
        [HttpGet("key")]
        public async Task<IActionResult> GetKey()
            => Ok(await _userService.GetKey(_userId));

        [HttpPost("key")]
        public async Task<IActionResult> PostKey([FromBody] PostKeyRequest request)
        {
            await _userService.InitializeUser(_userId, request.Key);

            return Created();
        }
    }
}
