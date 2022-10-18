using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportPayFee : Form
    {
        string id, month;
        int year;
        public ReportPayFee(string id, string month, int year)
        {
            InitializeComponent();
            this.id = id;
            this.month = month;
            this.year = year;
        }

        private void ReportPayFee_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'collegeDataSet.settings' table. You can move, or remove it, as needed.
            this.settingsTableAdapter.Fill(this.collegeDataSet.settings);
            try
            {
                // TODO: This line of code loads data into the 'PlantDataSet.CurrentStockByCategory' table. You can move, or remove it, as needed.
                this.receipt1TableAdapter.Fill(this.collegeDataSet.Receipt1, this.id, this.month, this.year);
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

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
