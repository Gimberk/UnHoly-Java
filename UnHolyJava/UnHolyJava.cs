using UnHolyJava;

string source = File.ReadAllText(Path.Combine(Directory.GetCurrentDirectory(), "content", "main.uhj"));

Parser parser = new(source);
parser.GenerateAST();