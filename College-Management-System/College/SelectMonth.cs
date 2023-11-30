using College.App_Code;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class SelectMonth : Form
    {
        public SelectMonth()
        {
            InitializeComponent();
            cboMonth.SelectedIndex = Int32.Parse(DateTime.Now.ToString("MM")) - 1;
            txtYear.Text = DateTime.Now.Year.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Common.command = false;
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Common.month = cboMonth.Text;
            Common.year = Int32.Parse(txtYear.Text);
            Common.command = true;
            this.Close();
        }
    }
}
