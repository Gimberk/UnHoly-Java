namespace UnHolyJava
{
    internal class Grammar
    {
        private readonly string grammarPath = 
            Path.Combine(Directory.GetCurrentDirectory(), "grammar.dat");

        private int lineIndex = 0;

        public bool JumpToHeading(string heading)
        {
            string[] content = File.ReadAllText(grammarPath).Split('\n');
            for (int i = 0; i < content.Length; i++)
            {
                string line = content[i].TrimEnd();
                if (line == "#" + heading)
                {
                    lineIndex = i;
                    return true;
                }
            }
            Console.WriteLine("No specified declaration of heading: " + heading);
            return false;
        }

        public List<string> ReadHeading()
        {
            List<string> values = new();
            string[] content = File.ReadAllText(grammarPath).Split('\n');
            lineIndex++;
            for (int i = lineIndex; i < content.Length; i++)
            {
                string line = content[i];
                if (line.StartsWith('#')) break;
                line = line.TrimEnd();
                values.Add(line);
            }
            return values;
        }
    }
}