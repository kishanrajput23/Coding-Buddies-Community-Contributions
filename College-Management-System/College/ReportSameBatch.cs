using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportSameBatch : Form
    {
        int batchCode;
        public ReportSameBatch(int batchCode)
        {
            InitializeComponent();
            this.batchCode = batchCode;
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ReportSameBatch_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'collegeDataSet.settings' table. You can move, or remove it, as needed.
            try
            {
                // TODO: This line of code loads data into the 'PlantDataSet.CurrentStockByCategory' table. You can move, or remove it, as needed.
                this.sameBatchStudentsTableAdapter.Fill(this.collegeDataSet.SameBatchStudents, this.batchCode);
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
