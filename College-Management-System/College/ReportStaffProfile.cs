using Microsoft.Reporting.WinForms;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ReportStaffProfile : Form
    {
        string id;
        public ReportStaffProfile(string id)
        {
            InitializeComponent();
            this.id = id;
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ReportStaffProfile_Load(object sender, EventArgs e)
        {
            try
            {
                // TODO: This line of code loads data into the 'PlantDataSet.CurrentStockByCategory' table. You can move, or remove it, as needed.
                this.staffProfileTableAdapter.Fill(this.collegeDataSet.StaffProfile, id);
                this.settingsTableAdapter.Fill(this.collegeDataSet.settings);
                this.qualificationTableAdapter.Fill(this.collegeDataSet.Qualification, this.id);
                reportViewer1.SetDisplayMode(DisplayMode.PrintLayout);
                reportViewer1.ZoomMode = ZoomMode.Percent;
                reportViewer1.ZoomPercent = 100;
                this.reportViewer1.RefreshReport();
            }
            catch (Exception ex)
            {

            }
        }

        private void reportViewer1_Load(object sender, EventArgs e)
        {

        }
    }
}
