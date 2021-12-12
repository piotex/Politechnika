﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SerialTransmition
{
    public partial class Form1 : Form
    {
        private SerialPort serialPort1;
        static string StatusText;
        public Form1()
        {
            InitializeComponent();
            serialPort1 = new SerialPort();
            serialPort1.DataReceived += serialPort1_DataReceived;
        }
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            StatusText = serialPort1.ReadExisting();
            Invoke(new EventHandler(DisplayThreadText));
        }
        private void DisplayThreadText(object sender, EventArgs e)
        {
            WriteStatusLine(StatusText);
        }
        private void WriteStatusLine(string text)
        {
            textBox_Get.Text += text + "\r\n";
        }
        private void button_Send_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen && textBox_Send.Text.Length > 0)
            {
                //serialPort1.Write("!" + textBox_Send.Text);
                serialPort1.Write(textBox_Send.Text+"\n");

                for (int i = 60; i < 120; i++)
                {
                    serialPort1.Write("q1:"+i+";q2:"+i+";q3:"+i+";q4:"+i+";q5:"+i+";\n");
                    Thread.Sleep(100);
                }
            }
            else
            {
                MessageBox.Show("Problem przy wysylaniu");
            }
        }

        private void button_Connect_Click(object sender, EventArgs e)
        {
            if (comboBox_Port.Text.Trim().Length == 0)
            {
                MessageBox.Show("Select a port and try again", Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            if (comboBox_Speed.Text.Trim().Length == 0)
            {
                MessageBox.Show("Select port connect speed and try again", Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            serialPort1.PortName = comboBox_Port.Text.Trim();
            serialPort1.BaudRate = Convert.ToInt32(comboBox_Speed.Text);
            serialPort1.Open();

            if (serialPort1.IsOpen)
            {
                button_Connect.Enabled = false;
                button_Disconnect.Enabled = true;
            }
        }

        private void button_Disconnect_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                button_Disconnect.Enabled = false;
                button_Connect.Enabled = true;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();

            foreach (string port in ports)
            {
                comboBox_Port.Items.Add(port);
            }

            comboBox_Speed.SelectedIndex = 11;
        }

        private void button_clearAll_Click(object sender, EventArgs e)
        {
            textBox_Get.Text = "";
            textBox_Send.Text = "";
        }
    }
}
