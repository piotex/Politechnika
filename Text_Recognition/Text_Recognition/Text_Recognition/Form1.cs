using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tesseract;

namespace Text_Recognition
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                var img = new Bitmap(openFile.FileName);
                Pix img2 = Pix.LoadFromFile(openFile.FileName);

                var ocr = new TesseractEngine("./tessdata","eng", EngineMode.Default);
                var page = ocr.Process(img2);
                textBox1.Text = page.GetText();
            }

        }



        private void button2_Click(object sender, EventArgs e)
        {
            //make_Magic();
            make_Magic_2();
        }
        private void zapisz(string pytanie, string odp, int numer)
        {
            string tmp = "";



            string path = @"C:\Users\pkubo\OneDrive\Dokumenty\GitHub\Politechnika\Text_Recognition\hash\pytania\" + numer + ".txt";
            if (!File.Exists(path))
            {
                if (odp == "X001")
                {
                    path = @"C:\Users\pkubo\OneDrive\Dokumenty\GitHub\Politechnika\Text_Recognition\hash\pytania\BrakOdp\" + numer + ".txt";
                }
                // Create a file to write to.
                using (StreamWriter sw = File.CreateText(path))
                {
                    sw.WriteLine(odp);
                    sw.WriteLine(pytanie);
                    sw.WriteLine("TAK");
                    sw.WriteLine("NIE");
                    sw.WriteLine("BRAK ODPOWIEDZI");

                }
            }
        }
        private void make_Magic()
        {
            string path = @"C:\Users\pkubo\OneDrive\Dokumenty\GitHub\Politechnika\Text_Recognition\hash\h1.txt";
            string text = System.IO.File.ReadAllText(path);

            bool _pytanie = false;
            bool _odp = false;

            int numer = 0;
            string pytanie = "";
            string odp = "";

            for (int i = 0; i < text.Length; i++)
            {
                char znak = text[i];
                if (znak == '.' && !_pytanie)
                {
                    _odp = false;
                    _pytanie = true;
                }
                if (znak == '\n' && _pytanie)
                {
                    _pytanie = false;
                    _odp = true;
                }

                if (_pytanie)
                {
                    if (!(znak <= 57 && znak >= 48))
                    {
                        pytanie += znak;
                    }
                }
                if (_odp)
                {
                    if (!(znak <= 57 && znak >= 48))
                    {
                        if (znak == 'F')
                        {
                            odp = "X01";
                            zapisz(pytanie, odp, numer);
                            pytanie = "";
                            odp = "";
                            numer++;
                            continue;
                        }
                        if (znak == 'P')
                        {
                            odp = "X10";
                            zapisz(pytanie, odp, numer);
                            pytanie = "";
                            odp = "";
                            numer++;
                            continue;
                        }
                    }
                }
            }
        }

        private void make_Magic_2()
        {
            string path = @"C:\Users\pkubo\OneDrive\Dokumenty\GitHub\Politechnika\Text_Recognition\hash\h1.txt";
            string text = System.IO.File.ReadAllText(path);

            bool gotowy = false;

            int numer = 0;
            
            string pytanie = "";
            string odp = "";

            for (int i = 0; i < text.Length; i++)
            {
                char znak = text[i];
                if (znak == '\n' && gotowy)
                {
                    znak = text[i-2];

                    if (znak == ' ')
                    {
                        int cc = 0;
                        while (text[i-cc-2] == ' ')
                        {
                            cc++;
                        }
                        znak = text[i-cc-2];
                    }
                    if (znak == 'F')
                        odp = "X010";
                    if (znak == 'P')
                        odp = "X100";
                    if (znak == '?')
                        odp = "X001";

                    zapisz(pytanie, odp, numer);
                    pytanie = "";
                    odp = "";
                    gotowy = false;
                    numer++;
                    continue;
                }
                if (znak == '\n' && !gotowy)
                {
                    gotowy = true;
                }
                if (!gotowy)
                {
                    pytanie += znak;
                }

                
            }
        }
    }
}
