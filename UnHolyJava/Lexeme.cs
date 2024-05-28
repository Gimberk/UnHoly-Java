namespace UnHolyJava
{
    internal class Lexeme(Token type, string repr)
    {
        public Token type = type;
        public string repr = repr;
    }

    public enum Token
    {
        NULL, CONSTANT, IDENTIFIER, TERMINATOR, KEYWORD, OPERATOR
    }
}