using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportSingleStudentProfle : Form
    {
        string studentId;
        public ReportSingleStudentProfle(string student)
        {
            InitializeComponent();
            this.studentId = student;
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ReportSingleStudentProfle_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'collegeDataSet.settings' table. You can move, or remove it, as needed.

            try
            {
                // TODO: This line of code loads data into the 'PlantDataSet.CurrentStockByCategory' table. You can move, or remove it, as needed.
                this.singleStudentTableAdapter.Fill(this.collegeDataSet.singleStudent, this.studentId);
                this.qualificationTableAdapter.Fill(this.collegeDataSet.Qualification, this.studentId);
                this.settingsTableAdapter.Fill(this.collegeDataSet.settings);
                reportViewer1.SetDisplayMode(DisplayMode.PrintLayout);
                reportViewer1.ZoomMode = ZoomMode.Percent;
                reportViewer1.ZoomPercent = 100;
                this.reportViewer1.RefreshReport();
            }
            catch (Exception ex)
            {

            }
        }
    }
}
