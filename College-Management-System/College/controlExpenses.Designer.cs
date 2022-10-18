namespace College
{
    partial class controlExpenses
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.button4 = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.txtId = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtNote = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtAmount = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.cboTypes = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.txtDate = new System.Windows.Forms.DateTimePicker();
            this.button2 = new System.Windows.Forms.Button();
            this.ledgerGrid = new System.Windows.Forms.DataGridView();
            this.label7 = new System.Windows.Forms.Label();
            this.lblDebit = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.lblCredit = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.lblBalance = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.txtReason = new System.Windows.Forms.ComboBox();
            this.button3 = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ledgerGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.pictureBox5);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1045, 52);
            this.panel1.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(47, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(166, 21);
            this.label1.TabIndex = 0;
            this.label1.Text = "Expenditure Section";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.button1);
            this.panel2.Controls.Add(this.button4);
            this.panel2.Controls.Add(this.lblBalance);
            this.panel2.Controls.Add(this.label11);
            this.panel2.Controls.Add(this.lblCredit);
            this.panel2.Controls.Add(this.label9);
            this.panel2.Controls.Add(this.lblDebit);
            this.panel2.Controls.Add(this.label7);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(0, 594);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1045, 82);
            this.panel2.TabIndex = 2;
            // 
            // button4
            // 
            this.button4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button4.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button4.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.ForeColor = System.Drawing.Color.White;
            this.button4.Location = new System.Drawing.Point(38, 16);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(133, 44);
            this.button4.TabIndex = 20;
            this.button4.Text = "Daily Entry";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.button3);
            this.panel3.Controls.Add(this.button2);
            this.panel3.Controls.Add(this.txtDate);
            this.panel3.Controls.Add(this.txtReason);
            this.panel3.Controls.Add(this.cboTypes);
            this.panel3.Controls.Add(this.label12);
            this.panel3.Controls.Add(this.txtAmount);
            this.panel3.Controls.Add(this.label6);
            this.panel3.Controls.Add(this.txtNote);
            this.panel3.Controls.Add(this.label5);
            this.panel3.Controls.Add(this.label2);
            this.panel3.Controls.Add(this.txtId);
            this.panel3.Controls.Add(this.label4);
            this.panel3.Controls.Add(this.label3);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel3.Location = new System.Drawing.Point(0, 52);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1045, 175);
            this.panel3.TabIndex = 3;
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.ledgerGrid);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel4.Location = new System.Drawing.Point(0, 227);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(1045, 367);
            this.panel4.TabIndex = 4;
            // 
            // txtId
            // 
            this.txtId.Enabled = false;
            this.txtId.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtId.Location = new System.Drawing.Point(72, 46);
            this.txtId.Name = "txtId";
            this.txtId.Size = new System.Drawing.Size(416, 23);
            this.txtId.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(68, 79);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 19);
            this.label4.TabIndex = 15;
            this.label4.Text = "Reason";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(68, 14);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(103, 19);
            this.label3.TabIndex = 14;
            this.label3.Text = "Ledger Code:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(293, 79);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 19);
            this.label2.TabIndex = 15;
            this.label2.Text = "Note";
            // 
            // txtNote
            // 
            this.txtNote.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtNote.Location = new System.Drawing.Point(290, 110);
            this.txtNote.Name = "txtNote";
            this.txtNote.Size = new System.Drawing.Size(198, 23);
            this.txtNote.TabIndex = 13;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(496, 15);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(67, 19);
            this.label5.TabIndex = 15;
            this.label5.Text = "Amount:";
            // 
            // txtAmount
            // 
            this.txtAmount.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAmount.Location = new System.Drawing.Point(500, 46);
            this.txtAmount.Name = "txtAmount";
            this.txtAmount.Size = new System.Drawing.Size(223, 23);
            this.txtAmount.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(496, 79);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(47, 19);
            this.label6.TabIndex = 15;
            this.label6.Text = "Date:";
            // 
            // cboTypes
            // 
            this.cboTypes.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cboTypes.FormattingEnabled = true;
            this.cboTypes.Items.AddRange(new object[] {
            "Debit",
            "Credit"});
            this.cboTypes.Location = new System.Drawing.Point(756, 46);
            this.cboTypes.Name = "cboTypes";
            this.cboTypes.Size = new System.Drawing.Size(206, 24);
            this.cboTypes.TabIndex = 20;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.ForeColor = System.Drawing.Color.White;
            this.label12.Location = new System.Drawing.Point(752, 15);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(45, 19);
            this.label12.TabIndex = 21;
            this.label12.Text = "Type:";
            // 
            // txtDate
            // 
            this.txtDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.txtDate.Location = new System.Drawing.Point(500, 110);
            this.txtDate.Name = "txtDate";
            this.txtDate.Size = new System.Drawing.Size(223, 23);
            this.txtDate.TabIndex = 22;
            // 
            // button2
            // 
            this.button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button2.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button2.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(756, 103);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(136, 30);
            this.button2.TabIndex = 23;
            this.button2.Text = "Submit";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // ledgerGrid
            // 
            this.ledgerGrid.AllowUserToAddRows = false;
            this.ledgerGrid.AllowUserToDeleteRows = false;
            this.ledgerGrid.AllowUserToResizeColumns = false;
            this.ledgerGrid.AllowUserToResizeRows = false;
            this.ledgerGrid.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.ledgerGrid.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.ledgerGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ledgerGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ledgerGrid.Location = new System.Drawing.Point(0, 0);
            this.ledgerGrid.Name = "ledgerGrid";
            this.ledgerGrid.RowHeadersVisible = false;
            this.ledgerGrid.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.False;
            this.ledgerGrid.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.ledgerGrid.Size = new System.Drawing.Size(1045, 367);
            this.ledgerGrid.TabIndex = 1;
            this.ledgerGrid.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.ledgerGrid_CellClick);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(406, 31);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(50, 19);
            this.label7.TabIndex = 15;
            this.label7.Text = "Debit:";
            // 
            // lblDebit
            // 
            this.lblDebit.AutoSize = true;
            this.lblDebit.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDebit.ForeColor = System.Drawing.Color.White;
            this.lblDebit.Location = new System.Drawing.Point(476, 31);
            this.lblDebit.Name = "lblDebit";
            this.lblDebit.Size = new System.Drawing.Size(17, 19);
            this.lblDebit.TabIndex = 15;
            this.lblDebit.Text = "0";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.White;
            this.label9.Location = new System.Drawing.Point(557, 31);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(55, 19);
            this.label9.TabIndex = 15;
            this.label9.Text = "Credit:";
            this.label9.Click += new System.EventHandler(this.label9_Click);
            // 
            // lblCredit
            // 
            this.lblCredit.AutoSize = true;
            this.lblCredit.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCredit.ForeColor = System.Drawing.Color.White;
            this.lblCredit.Location = new System.Drawing.Point(631, 31);
            this.lblCredit.Name = "lblCredit";
            this.lblCredit.Size = new System.Drawing.Size(17, 19);
            this.lblCredit.TabIndex = 15;
            this.lblCredit.Text = "0";
            this.lblCredit.Click += new System.EventHandler(this.label9_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.Color.White;
            this.label11.Location = new System.Drawing.Point(714, 31);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(71, 19);
            this.label11.TabIndex = 15;
            this.label11.Text = "Balance:";
            this.label11.Click += new System.EventHandler(this.label9_Click);
            // 
            // lblBalance
            // 
            this.lblBalance.AutoSize = true;
            this.lblBalance.Font = new System.Drawing.Font("Century Gothic", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblBalance.ForeColor = System.Drawing.Color.White;
            this.lblBalance.Location = new System.Drawing.Point(797, 31);
            this.lblBalance.Name = "lblBalance";
            this.lblBalance.Size = new System.Drawing.Size(17, 19);
            this.lblBalance.TabIndex = 15;
            this.lblBalance.Text = "0";
            this.lblBalance.Click += new System.EventHandler(this.label9_Click);
            // 
            // button1
            // 
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button1.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(177, 16);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(133, 44);
            this.button1.TabIndex = 20;
            this.button1.Text = "Monthly Entry";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.mothly);
            // 
            // pictureBox5
            // 
            this.pictureBox5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox5.Image = global::College.Properties.Resources.markatt;
            this.pictureBox5.Location = new System.Drawing.Point(16, 13);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(25, 25);
            this.pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox5.TabIndex = 3;
            this.pictureBox5.TabStop = false;
            // 
            // txtReason
            // 
            this.txtReason.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtReason.FormattingEnabled = true;
            this.txtReason.Items.AddRange(new object[] {
            "Expenditure",
            "Others"});
            this.txtReason.Location = new System.Drawing.Point(72, 110);
            this.txtReason.Name = "txtReason";
            this.txtReason.Size = new System.Drawing.Size(206, 24);
            this.txtReason.TabIndex = 20;
            // 
            // button3
            // 
            this.button3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button3.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button3.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(209)))), ((int)(((byte)(31)))), ((int)(((byte)(55)))));
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ForeColor = System.Drawing.Color.White;
            this.button3.Location = new System.Drawing.Point(898, 103);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(64, 30);
            this.button3.TabIndex = 23;
            this.button3.Text = "Reset";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.reset);
            // 
            // controlExpenses
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(21)))), ((int)(((byte)(21)))), ((int)(((byte)(21)))));
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Name = "controlExpenses";
            this.Size = new System.Drawing.Size(1045, 676);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ledgerGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.TextBox txtAmount;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtNote;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtId;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cboTypes;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.DateTimePicker txtDate;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridView ledgerGrid;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label lblDebit;
        private System.Windows.Forms.Label lblBalance;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label lblCredit;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox txtReason;
        private System.Windows.Forms.Button button3;
    }
}
