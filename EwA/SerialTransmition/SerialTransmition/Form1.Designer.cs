
namespace SerialTransmition
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox_Port = new System.Windows.Forms.ComboBox();
            this.comboBox_Speed = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.button_Connect = new System.Windows.Forms.Button();
            this.button_Disconnect = new System.Windows.Forms.Button();
            this.textBox_Get = new System.Windows.Forms.TextBox();
            this.textBox_Send = new System.Windows.Forms.TextBox();
            this.button_Send = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Port: ";
            // 
            // comboBox_Port
            // 
            this.comboBox_Port.FormattingEnabled = true;
            this.comboBox_Port.Location = new System.Drawing.Point(53, 12);
            this.comboBox_Port.Name = "comboBox_Port";
            this.comboBox_Port.Size = new System.Drawing.Size(121, 23);
            this.comboBox_Port.TabIndex = 1;
            // 
            // comboBox_Speed
            // 
            this.comboBox_Speed.FormattingEnabled = true;
            this.comboBox_Speed.Items.AddRange(new object[] {
            "75",
            "110",
            "134",
            "150",
            "300",
            "600",
            "1200",
            "1800",
            "2400",
            "4800",
            "7200",
            "9600",
            "14400",
            "19200",
            "38400",
            "57600",
            "115200",
            "128000"});
            this.comboBox_Speed.Location = new System.Drawing.Point(242, 12);
            this.comboBox_Speed.Name = "comboBox_Speed";
            this.comboBox_Speed.Size = new System.Drawing.Size(121, 23);
            this.comboBox_Speed.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(191, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "Speed: ";
            // 
            // button_Connect
            // 
            this.button_Connect.Location = new System.Drawing.Point(384, 12);
            this.button_Connect.Name = "button_Connect";
            this.button_Connect.Size = new System.Drawing.Size(75, 23);
            this.button_Connect.TabIndex = 4;
            this.button_Connect.Text = "Connect";
            this.button_Connect.UseVisualStyleBackColor = true;
            this.button_Connect.Click += new System.EventHandler(this.button_Connect_Click);
            // 
            // button_Disconnect
            // 
            this.button_Disconnect.Location = new System.Drawing.Point(465, 12);
            this.button_Disconnect.Name = "button_Disconnect";
            this.button_Disconnect.Size = new System.Drawing.Size(75, 23);
            this.button_Disconnect.TabIndex = 5;
            this.button_Disconnect.Text = "Disconnect";
            this.button_Disconnect.UseVisualStyleBackColor = true;
            this.button_Disconnect.Click += new System.EventHandler(this.button_Disconnect_Click);
            // 
            // textBox_Get
            // 
            this.textBox_Get.Location = new System.Drawing.Point(12, 50);
            this.textBox_Get.Multiline = true;
            this.textBox_Get.Name = "textBox_Get";
            this.textBox_Get.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox_Get.Size = new System.Drawing.Size(881, 412);
            this.textBox_Get.TabIndex = 6;
            // 
            // textBox_Send
            // 
            this.textBox_Send.Location = new System.Drawing.Point(12, 468);
            this.textBox_Send.Multiline = true;
            this.textBox_Send.Name = "textBox_Send";
            this.textBox_Send.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox_Send.Size = new System.Drawing.Size(675, 49);
            this.textBox_Send.TabIndex = 7;
            // 
            // button_Send
            // 
            this.button_Send.Location = new System.Drawing.Point(693, 467);
            this.button_Send.Name = "button_Send";
            this.button_Send.Size = new System.Drawing.Size(200, 50);
            this.button_Send.TabIndex = 8;
            this.button_Send.Text = "Send";
            this.button_Send.UseVisualStyleBackColor = true;
            this.button_Send.Click += new System.EventHandler(this.button_Send_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(905, 524);
            this.Controls.Add(this.button_Send);
            this.Controls.Add(this.textBox_Send);
            this.Controls.Add(this.textBox_Get);
            this.Controls.Add(this.button_Disconnect);
            this.Controls.Add(this.button_Connect);
            this.Controls.Add(this.comboBox_Speed);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboBox_Port);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox_Port;
        private System.Windows.Forms.ComboBox comboBox_Speed;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button_Connect;
        private System.Windows.Forms.Button button_Disconnect;
        private System.Windows.Forms.TextBox textBox_Get;
        private System.Windows.Forms.TextBox textBox_Send;
        private System.Windows.Forms.Button button_Send;
    }
}

