using College.App_Code;
using System;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class ManageBatch : Form
    {
        public ManageBatch()
        {
            InitializeComponent();
            try
            {
                bindGrid();
            }
            catch (Exception ex)
            {

            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string batchName = (string.IsNullOrWhiteSpace(txtBatchName.Text)) ? "" : txtBatchName.Text;

                Batch obj = new Batch();
                obj.batchName = batchName;

                obj.addClass();
                Done d = new Done();
                d.ShowDialog();
                resetData();
                bindGrid();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        public void resetData()
        {
            txtBatchName.Text = "";
        }
        public void bindGrid()
        {
            try
            {
                Batch obj = new Batch();
                DataTable dt = obj.getAllBatches();
                classGrid.DataSource = dt;
            }
            catch (Exception ex)
            {

            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            resetData();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                YesNo o = new YesNo();
                o.ShowDialog();
                if (Common.command == true)
                {
                    int seriel = Int32.Parse(classGrid.SelectedRows[0].Cells[0].Value.ToString());
                    Batch obj = new Batch();
                    obj.seriel = seriel;
                    obj.delete();
                    Done d = new Done();
                    d.ShowDialog();

                    resetData();
                    bindGrid();
                }
            }
            catch (Exception ex)
            {

            }
        }
    }
}
