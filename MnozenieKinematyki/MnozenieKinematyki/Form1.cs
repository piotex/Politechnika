using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MnozenieKinematyki
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private List<List<string>> mac1;//= new List<List<string>>();
        private List<List<string>> mac2; //= new List<List<string>>();
        private List<List<string>> mac3;// new List<List<string>>();

        private void button1_Click(object sender, EventArgs e)
        {
            init();
        }

        void init()
        {
            mac1 = new List<List<string>>();
            mac2 = new List<List<string>>();
            mac3 = new List<List<string>>();

            mac1.Add(new List<string> { textBox1.Text,  textBox2.Text,  textBox3.Text,  textBox4.Text, });
            mac1.Add(new List<string> { textBox5.Text,  textBox6.Text,  textBox7.Text,  textBox8.Text, });
            mac1.Add(new List<string> { textBox9.Text,  textBox10.Text, textBox11.Text, textBox12.Text, });
            mac1.Add(new List<string> { textBox13.Text, textBox14.Text, textBox15.Text, textBox16.Text, });

            mac2.Add(new List<string> { textBox17.Text, textBox18.Text, textBox19.Text, textBox20.Text, });
            mac2.Add(new List<string> { textBox21.Text, textBox22.Text, textBox23.Text, textBox24.Text, });
            mac2.Add(new List<string> { textBox25.Text, textBox26.Text, textBox27.Text, textBox28.Text, });
            mac2.Add(new List<string> { textBox29.Text, textBox30.Text, textBox31.Text, textBox32.Text, });

            mac3.Add(new List<string>{"","","",""});
            mac3.Add(new List<string>{"","","",""});
            mac3.Add(new List<string>{"","","",""});
            mac3.Add(new List<string>{"","","",""});

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    string a = mac1[i][j];
                    string b = mac2[j][i];

                    if (a == "0")
                    {
                        mac3[i][j] = "0";
                        break;
                    }
                    if (b == "0")
                    {
                        mac3[i][j] = "0";
                        break;
                    }
                    if (b == "1")
                        b = ""; 
                    if (a == "1")
                        a = "";
                    if (a == "" && b == "")
                        a = "1";

                    mac3[i][j] = a + " " + b;
                }
            }

            textBox33.Text = mac3[0][0];
            textBox34.Text = mac3[0][1];
            textBox35.Text = mac3[0][2];
            textBox36.Text = mac3[0][3];

            textBox37.Text = mac3[1][0];
            textBox38.Text = mac3[1][1];
            textBox39.Text = mac3[1][2];
            textBox40.Text = mac3[1][3];
            
            textBox41.Text = mac3[2][0];
            textBox42.Text = mac3[2][1];
            textBox43.Text = mac3[2][2];
            textBox44.Text = mac3[2][3];

            textBox45.Text = mac3[3][0];
            textBox46.Text = mac3[3][1];
            textBox47.Text = mac3[3][2];
            textBox48.Text = mac3[3][3];
        }
    }
}
