using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace PlayingAndTesting
{
    public class Animal
    {
        string kindOfAnimal;
        string name;
        int numberOfLegs;
        int height;
        int length;
        string color;
        bool hasTail,
            isMammal,
            spellingCorrect;
        bool caal = true;
       public static int count = 100;

        public Animal(int kol)
        {
            numberOfLegs = kol + count;
        }
    }    
    class Program
    {
       static int Add(params int[] i)
        {
            int sum = 0;
            foreach (int s in i)
                sum += s;
            return sum;
        }

        private string name;
        public string Name => name;

       static void Main()
        {
            //Console.WriteLine(Add(5, 4, 1));
            //Console.WriteLine("Результат работы тернарного оператора: {}");
            var s1 = 0; //неявно объявленная переменная
            Program prog = new Program();
            //prog.Name = "Tom";

            Console.WriteLine(prog.Name);

            //sArray = new string[10];
            string[] sArray = new string[10];
            int[] iArray = new int[10];
            //Console.WriteLine(iArray.Count());
            //Console.WriteLine(sArray.Count());
            Animal Barsik = new Animal(10);
            Animal.count += 200;
            int x = 127;
            long y = 0x7F; // шестнадцатеричная запись 127.
            double d = 1.27;
            double million = 1E06; // экспонента = 1.000.000
            float f = 1.001F;
            int a = unchecked (int.MinValue - 1);
            char[] mas = new char[5]; // объявление массива из 5 эл.
            int[,] masD = new int[3, 3]; // двумерный массив
            double t = (million >= d) ? million : d; //тернарный оператор
            //Console.WriteLine($" {a}");
            //Console.WriteLine($"Результат работы тернарного оператора: {t}");
            //Console.WriteLine(mas.LongLength);
            string sTring = "Hello World!";
            //foreach (char sT in sTring)
            //    Console.Write(sT);
        }
    }


}
