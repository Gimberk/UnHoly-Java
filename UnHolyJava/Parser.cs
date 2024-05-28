using Newtonsoft.Json;
using UnHolyJava.AST;

namespace UnHolyJava
{
    internal class Parser
    {
        private readonly string source;

        private readonly string output = Path.Combine(Directory.GetCurrentDirectory(), "AST.json");

        public Parser(string source)
        {
            this.source = source;
        }

        public bool GenerateAST()
        {
            Lexer lexer = new();
            if (!lexer.GenerateLexemes(source)) return false;

            Console.WriteLine("Lexemes:");
            foreach (Lexeme lex in lexer.lexemes)
            {
                Console.WriteLine(lex.repr + ", " + lex.type.ToString());
            }

            Console.WriteLine("\nGenerated AST:");
            Application program = new Application("PRGRAM");
            foreach (Lexeme lex in lexer.lexemes)
            {
                Node node = ParseNode(lex);
                if (node.type != NodeType.NULL) program.nodes.Add(node);
            }

            return true;
        }

        private Node ParseNode(Lexeme lex)
        {
            switch (lex.type)
            {
                case 
            }
        }
    }
}