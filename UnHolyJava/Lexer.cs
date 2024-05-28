namespace UnHolyJava
{
    internal class Lexer
    {
        public readonly List<Lexeme> lexemes = new();

        private readonly Grammar g = new();

        private List<string> keywords = new();
        private List<string> operators = new();

        public Lexer()
        {
            LoadGrammar();
        }

        public bool LoadGrammar()
        {
            if (!g.JumpToHeading("KEYWORDS"))
            {
                Console.WriteLine("Invalid Grammar File!");
                return false;
            }
            keywords = g.ReadHeading();
            if (!g.JumpToHeading("OPERATORS"))
            {
                Console.WriteLine("Invalid Grammar File!");
                return false;
            }
            operators = g.ReadHeading();
            return true;
        }

        public bool GenerateLexemes(string source)
        {
            if (source.Length == 0 || keywords.Count == 0)
            {
                Console.WriteLine("Failed to Generate Lexemes!");
                return false;
            }
            lexemes.Clear();

            string buffer = string.Empty;

            foreach (char c in source)
            {
                if (Terminate(c, buffer))
                {
                    if (buffer != " ")
                    {
                        Token type = Token.NULL;
                        if (buffer == ";") type = Token.TERMINATOR;
                        else if (keywords.Contains(buffer)) type = Token.KEYWORD;
                        else if (buffer.All(x => char.IsDigit(x))) type = Token.CONSTANT;
                        else if (buffer.All(x => char.IsLetterOrDigit(x))) type = Token.IDENTIFIER;
                        else if (operators.Contains(buffer)) type = Token.OPERATOR;
                        Lexeme lex = new(type, buffer);
                        lexemes.Add(lex);
                    }
                    buffer = string.Empty; // clear the buffer
                }
                if (buffer != " ") buffer += c;
            }

            if (!buffer.Equals(string.Empty))
            {
                if (buffer != " ")
                {
                    Token type = Token.CONSTANT;
                    if (buffer == ";") type = Token.TERMINATOR;
                    else if (keywords.Contains(buffer)) type = Token.KEYWORD;
                    else if (buffer.All(x => char.IsLetterOrDigit(x))) type = Token.IDENTIFIER;
                    Lexeme lex = new(type, buffer);
                    lexemes.Add(lex);
                }
                buffer = string.Empty; // clear the buffer
            }

            return true;
        }

        private bool Terminate(char c, string buffer)
        {
            if (buffer.Length == 0) return false;
            char first = buffer[0];
            return !(char.IsLetterOrDigit(first) && char.IsLetterOrDigit(c));
        }
    }
}
