using College.App_Code;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class SelectYear : Form
    {
        public SelectYear()
        {
            InitializeComponent();
            txtYear.Text = DateTime.Now.Year.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Common.command = true;
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Common.year = Int32.Parse(txtYear.Text);
            Common.command = true;
            this.Close();
        }
    }
}
