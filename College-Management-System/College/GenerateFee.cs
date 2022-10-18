using College.App_Code;
using System;
using System.Collections.Generic;
using System.Data;
using System.Threading;
using System.Windows.Forms;

namespace College
{
    public partial class GenerateFee : Form
    {
        public GenerateFee()
        {
            InitializeComponent();
            try
            {
                loadBatchData();
                loadClasses();
                cboMonth.SelectedIndex = 0;

                txtYear.Text = DateTime.Now.Year.ToString();
            }
            catch (Exception ex)
            {

            }
        }
        public void loadBatchData()
        {
            try
            {
                Dictionary<string, string> test = new Dictionary<string, string>();
                Batch b = new Batch();
                DataTable dt = b.getAllBatches();
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    test.Add(dt.Rows[i][0].ToString(), dt.Rows[i][1].ToString());
                }
                cboBatch.DataSource = new BindingSource(test, null);
                cboBatch.DisplayMember = "Value";
                cboBatch.ValueMember = "Key";

                cboBatch.SelectedIndex = 0;
            }
            catch (Exception ex)
            {

            }
        }
        public void loadClasses()
        {
            try
            {
                Dictionary<string, string> test = new Dictionary<string, string>();
                ClassList b = new ClassList();
                DataTable dt = b.getAllClasses();
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    test.Add(dt.Rows[i][0].ToString(), dt.Rows[i][1].ToString());
                }
                cboClass.DataSource = new BindingSource(test, null);
                cboClass.DisplayMember = "Value";
                cboClass.ValueMember = "Key";

                cboClass.SelectedIndex = 0;
            }
            catch (Exception ex)
            {

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int batchCode = Int32.Parse(((KeyValuePair<string, string>)cboBatch.SelectedItem).Key);
                int cls = Int32.Parse(((KeyValuePair<string, string>)cboClass.SelectedItem).Key);
                string month = cboMonth.Text;
                int year = Int32.Parse(txtYear.Text);
                Student std = new Student();
                std.batch = batchCode;
                std.classCode = cls;
                DataTable dt = std.getByBatchClass();
                double annualFund = 0;
                double examFee = 0;
                double admissionFee = 0;
                double fine = 0;
                double discount = 0;
                double totalAmount = 0;
                if (chkAnnualFund.Checked)
                {
                    annualFund = settings.annualFund;
                }
                if (chkExamFee.Checked)
                {
                    examFee = settings.examFee;
                }
                if (chkAdmissionFee.Checked)
                {
                    admissionFee = settings.admissionFee;
                }
                ClassList cl = new ClassList();
                cl.seriel = cls;
                double tuitionFee = cl.getTuitionFee();

                totalAmount = annualFund + examFee + fine + admissionFee;
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    generateCode();
                    string stdId = dt.Rows[i][1].ToString();
                    Fee f = new Fee();
                    f.seriel = bcode;
                    f.studentId = stdId;
                    f.month = month;
                    f.year = year;
                    discount = double.Parse(dt.Rows[i][15].ToString());
                    double d = discount / 100 * tuitionFee;
                    f.discount = d;
                    f.tuitionFee = tuitionFee - d;
                    f.annualFund = annualFund;
                    f.examFee = examFee;
                    f.admissionFee = admissionFee;
                    f.fine = fine;
                    f.totalAmount = totalAmount + tuitionFee - d;
                    f.received = false;
                    f.receivingDate = DateTime.Parse(DateTime.Now.ToShortDateString());
                    f.receivedBy = "-";
                    f.generateFee();
                    Thread.Sleep(1100);
                }

                Done dz = new Done();
                dz.ShowDialog();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        string bcode = "";
        public void generateCode()
        {
            bcode = "";
            DateTime dt = new DateTime(DateTime.Now.Year, 1, 1, 0, 0, 0, 0, DateTimeKind.Local);//from 1970/1/1 00:00:00 to now
            DateTime dtNow = DateTime.Now;
            TimeSpan result = dtNow.Subtract(dt);
            int minutes = Convert.ToInt32(result.TotalSeconds);
            bcode += minutes.ToString();
            int l = bcode.Length;
            if (l < 11)
            {
                for (int i = 1; i <= 11 - l; i++)
                {
                    bcode = "0" + bcode;
                }
            }
            bcode = DateTime.Now.ToString("yy") + bcode;
        }
    }
}
