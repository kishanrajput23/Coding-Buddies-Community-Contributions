namespace College
{
    partial class ReportSingleStudentProfle
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            Microsoft.Reporting.WinForms.ReportDataSource reportDataSource1 = new Microsoft.Reporting.WinForms.ReportDataSource();
            Microsoft.Reporting.WinForms.ReportDataSource reportDataSource2 = new Microsoft.Reporting.WinForms.ReportDataSource();
            Microsoft.Reporting.WinForms.ReportDataSource reportDataSource3 = new Microsoft.Reporting.WinForms.ReportDataSource();
            this.singleStudentBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.collegeDataSet = new College.App_Data.CollegeDataSet();
            this.settingsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.QualificationBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.panel3 = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.label2 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.reportViewer1 = new Microsoft.Reporting.WinForms.ReportViewer();
            this.singleStudentTableAdapter = new College.App_Data.CollegeDataSetTableAdapters.singleStudentTableAdapter();
            this.settingsTableAdapter = new College.App_Data.CollegeDataSetTableAdapters.settingsTableAdapter();
            this.qualificationBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.qualificationTableAdapter = new College.App_Data.CollegeDataSetTableAdapters.QualificationTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.singleStudentBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.collegeDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.settingsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.QualificationBindingSource)).BeginInit();
            this.panel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.qualificationBindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // singleStudentBindingSource
            // 
            this.singleStudentBindingSource.DataMember = "singleStudent";
            this.singleStudentBindingSource.DataSource = this.collegeDataSet;
            // 
            // collegeDataSet
            // 
            this.collegeDataSet.DataSetName = "CollegeDataSet";
            this.collegeDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // settingsBindingSource
            // 
            this.settingsBindingSource.DataMember = "settings";
            this.settingsBindingSource.DataSource = this.collegeDataSet;
            // 
            // QualificationBindingSource
            // 
            this.QualificationBindingSource.DataMember = "Qualification";
            this.QualificationBindingSource.DataSource = this.collegeDataSet;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Gray;
            this.panel3.Controls.Add(this.pictureBox2);
            this.panel3.Controls.Add(this.label2);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel3.Location = new System.Drawing.Point(10, 0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1164, 55);
            this.panel3.TabIndex = 12;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox2.Image = global::College.Properties.Resources.closewhite;
            this.pictureBox2.Location = new System.Drawing.Point(1130, 13);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(28, 28);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 31;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Click += new System.EventHandler(this.pictureBox2_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Consolas", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(22, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(240, 32);
            this.label2.TabIndex = 30;
            this.label2.Text = "STUDENT PROFILE";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.panel2.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel2.Location = new System.Drawing.Point(1174, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(10, 462);
            this.panel2.TabIndex = 11;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(10, 462);
            this.panel1.TabIndex = 10;
            // 
            // reportViewer1
            // 
            this.reportViewer1.Dock = System.Windows.Forms.DockStyle.Fill;
            reportDataSource1.Name = "DataSet1";
            reportDataSource1.Value = this.singleStudentBindingSource;
            reportDataSource2.Name = "DataSet2";
            reportDataSource2.Value = this.settingsBindingSource;
            reportDataSource3.Name = "DataSet3";
            reportDataSource3.Value = this.qualificationBindingSource1;
            this.reportViewer1.LocalReport.DataSources.Add(reportDataSource1);
            this.reportViewer1.LocalReport.DataSources.Add(reportDataSource2);
            this.reportViewer1.LocalReport.DataSources.Add(reportDataSource3);
            this.reportViewer1.LocalReport.ReportEmbeddedResource = "College.Reports.SingleStudentProfile.rdlc";
            this.reportViewer1.Location = new System.Drawing.Point(10, 55);
            this.reportViewer1.Name = "reportViewer1";
            this.reportViewer1.Size = new System.Drawing.Size(1164, 407);
            this.reportViewer1.TabIndex = 13;
            // 
            // singleStudentTableAdapter
            // 
            this.singleStudentTableAdapter.ClearBeforeFill = true;
            // 
            // settingsTableAdapter
            // 
            this.settingsTableAdapter.ClearBeforeFill = true;
            // 
            // qualificationBindingSource1
            // 
            this.qualificationBindingSource1.DataMember = "Qualification";
            this.qualificationBindingSource1.DataSource = this.collegeDataSet;
            // 
            // qualificationTableAdapter
            // 
            this.qualificationTableAdapter.ClearBeforeFill = true;
            // 
            // ReportSingleStudentProfle
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1184, 462);
            this.Controls.Add(this.reportViewer1);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "ReportSingleStudentProfle";
            this.Text = "ReportSingleStudentProfle";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.ReportSingleStudentProfle_Load);
            ((System.ComponentModel.ISupportInitialize)(this.singleStudentBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.collegeDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.settingsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.QualificationBindingSource)).EndInit();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.qualificationBindingSource1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel1;
        private Microsoft.Reporting.WinForms.ReportViewer reportViewer1;
        private System.Windows.Forms.BindingSource singleStudentBindingSource;
        private App_Data.CollegeDataSet collegeDataSet;
        private App_Data.CollegeDataSetTableAdapters.singleStudentTableAdapter singleStudentTableAdapter;
        private System.Windows.Forms.BindingSource settingsBindingSource;
        private App_Data.CollegeDataSetTableAdapters.settingsTableAdapter settingsTableAdapter;
        private System.Windows.Forms.BindingSource QualificationBindingSource;
        private System.Windows.Forms.BindingSource qualificationBindingSource1;
        private App_Data.CollegeDataSetTableAdapters.QualificationTableAdapter qualificationTableAdapter;
    }
}