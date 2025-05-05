namespace AuthService.Exceptions;

public class UsernameTakenException : Exception
{
    public UsernameTakenException()
        : base($"Username is already taken.")
    {
    }
}
