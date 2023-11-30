using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportTotalUnpaid : Form
    {
        public ReportTotalUnpaid()
        {
            InitializeComponent();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ReportDailyExpenditure_Load(object sender, EventArgs e)
        {
            try
            {
                // TODO: This line of code loads data into the 'collegeDataSet.settings' table. You can move, or remove it, as needed.
                this.settingsTableAdapter.Fill(this.collegeDataSet.settings);
                // TODO: This line of code loads data into the 'collegeDataSet.AllUnpaidFee' table. You can move, or remove it, as needed.
                this.allUnpaidFeeTableAdapter.Fill(this.collegeDataSet.AllUnpaidFee);
                reportViewer1.SetDisplayMode(DisplayMode.PrintLayout);
                reportViewer1.ZoomMode = ZoomMode.Percent;
                reportViewer1.ZoomPercent = 100;
                this.reportViewer1.RefreshReport();
            }
            catch (Exception EX)
            {

            }
        }
    }
}
