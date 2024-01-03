using College.App_Code;
using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class SelectBatch : Form
    {
        public SelectBatch()
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
            Common.command = false;
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                Common.batchCode = Int32.Parse(((KeyValuePair<string, string>)cboBatch.SelectedItem).Key);
                Common.classCode = Int32.Parse(((KeyValuePair<string, string>)cboClass.SelectedItem).Key);
                Common.month = cboMonth.Text;
                Common.year = Int32.Parse(txtYear.Text);
                Common.command = true;
                this.Close();
            }
            catch (Exception ex)
            {


            }
        }
    }
}
