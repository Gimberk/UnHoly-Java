namespace UnHolyJava.AST
{
    // for use with the AST
    public abstract class Node
    {
        public NodeType type;
        public string? repr;

        public override string ToString()
        {
            return $"Repr: {repr}, Type: {type}";
        }
    }

    public enum NodeType
    {
        NULL,

        PROGRAM, VAR_DECL,

        NUMBER_LIT, NULL_LIT, IDENTIFIER, BINARY_EXPR, ASSIGNMENT_EXPR
    }

    internal class Expr : Node { }

    internal class Application : Node
    {
        public readonly List<Node> nodes;

        public Application(string repr)
        {
            nodes = new();
            this.repr = repr; type = NodeType.PROGRAM;
        }
    }

    internal class NullLiteral : Node { }

    internal class NumLiteral : Node { }

    internal class Identifier : Node { }

    internal class AssignmentExpr : Expr { }

    internal class BinaryExpr : Expr
    {
        private Expr left, right;
        private string operation;
    }
}
