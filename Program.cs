using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalcularEdad
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Paradigma Imperativo \n");
            int AñoNac = 0;
            DateTime AñoActual = DateTime.Now;
            int Edad = 0;

            Console.WriteLine("Ingrese su Fecha de Nacimiento");
            AñoNac = int.Parse(Console.ReadLine());
            int Response = CalcularEdad(AñoNac);
            Console.WriteLine("La EDAD del Primer Llamado es: {0}", Response);

            Console.ReadLine();
            Console.WriteLine("Ingrese su Fecha de Nacimiento");
            AñoNac = int.Parse(Console.ReadLine());
            Response = CalcularEdad(AñoNac);
            //Console.WriteLine(CalcularEdad);
            Console.WriteLine("La EDAD es: {0}", Response);
            Console.ReadKey();
        }

        static int CalcularEdad(int AñoNac)
        {
            Console.WriteLine("Paradigma Imperativo con Funciones \n");
            //int AñoNac = 0;
            DateTime AñoActual = DateTime.Now;
            int Edad = 0;
            //Console.WriteLine("Ingrese su Fecha de Nacimiento");
            //Console.Read();
            //AñoNac = int.Parse(Console.ReadLine());

            Edad = AñoActual.Year - AñoNac;

            Console.WriteLine("La Edad de la Persona es: " + Edad);
            //Console.Read();
            return Edad;
        }
    }
}
