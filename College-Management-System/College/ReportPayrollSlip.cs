using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportPayrollSlip : Form
    {
        int id;
        public ReportPayrollSlip(int ID)
        {
            InitializeComponent();
            this.id = ID;
        }

        private void ReportPayrollSlip_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'collegeDataSet.settings' table. You can move, or remove it, as needed.
            this.settingsTableAdapter.Fill(this.collegeDataSet.settings);

            try
            {
                // TODO: This line of code loads data into the 'PlantDataSet.PaySlip' table. You can move, or remove it, as needed.
                this.paySlipTableAdapter.Fill(this.collegeDataSet.PaySlip, this.id);
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
