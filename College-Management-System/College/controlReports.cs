using College.App_Code;
using System.Windows.Forms;

namespace College
{
    public partial class controlReports : UserControl
    {
        private static controlReports _instance;
        public static controlReports Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlReports();
                }
                return _instance;
            }
        }
        public controlReports()
        {
            InitializeComponent();
        }

        private void label15_Click(object sender, System.EventArgs e)
        {
            SelectBatch b = new SelectBatch();
            b.ShowDialog();
            if (Common.command == true)
            {
                ReportBatchStudents obj = new ReportBatchStudents(Common.batchCode, Common.classCode);
                obj.ShowDialog();
            }
        }

        private void label19_Click(object sender, System.EventArgs e)
        {
            SelectBatch b = new SelectBatch();
            b.ShowDialog();
            if (Common.command == true)
            {
                ReportSameBatch obj = new ReportSameBatch(Common.batchCode);
                obj.ShowDialog();
            }
        }

        private void label17_Click(object sender, System.EventArgs e)
        {
            SelectBatch b = new SelectBatch();
            b.ShowDialog();
            if (Common.command == true)
            {
                ReportStudentsOnScholarship obj = new ReportStudentsOnScholarship(Common.batchCode);
                obj.ShowDialog();
            }
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label9_Click(object sender, System.EventArgs e)
        {
            ReportMonthlyExpenditure obj = new ReportMonthlyExpenditure();
            obj.ShowDialog();
        }

        private void label10_Click(object sender, System.EventArgs e)
        {
            ReportAnnualExpenditure obj = new ReportAnnualExpenditure();
            obj.ShowDialog();
        }

        private void label11_Click(object sender, System.EventArgs e)
        {
            ReportMonthlyStatement obj = new ReportMonthlyStatement();
            obj.ShowDialog();
        }

        private void label3_Click(object sender, System.EventArgs e)
        {
            ReportMonthlyFee obj = new ReportMonthlyFee();
            obj.ShowDialog();
        }

        private void label4_Click(object sender, System.EventArgs e)
        {
            ReportAnnualPaidFee obj = new ReportAnnualPaidFee();
            obj.ShowDialog();
        }

        private void label5_Click(object sender, System.EventArgs e)
        {
            ReportTotalUnpaid obj = new ReportTotalUnpaid();
            obj.ShowDialog();
        }

        private void label6_Click(object sender, System.EventArgs e)
        {
            ReportMonthlyUnpaid obj = new ReportMonthlyUnpaid();
            obj.ShowDialog();
        }

        private void label27_Click(object sender, System.EventArgs e)
        {
            ReportClassMonthlyUnpaid obj = new ReportClassMonthlyUnpaid();
            obj.ShowDialog();
        }

        private void label14_Click(object sender, System.EventArgs e)
        {
            ReportMonthlySalary obj = new ReportMonthlySalary();
            obj.ShowDialog();
        }

        private void label8_Click(object sender, System.EventArgs e)
        {
            ReportDailyExpenditure obj = new ReportDailyExpenditure();
            obj.ShowDialog();
        }
    }
}
