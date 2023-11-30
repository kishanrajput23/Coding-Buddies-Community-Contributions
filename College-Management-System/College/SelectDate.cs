using College.App_Code;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class SelectDate : Form
    {
        public SelectDate()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Common.command = false;
            this.Close();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Common.date = txtDate.Value;
            Common.command = true;
            this.Close();
        }
    }
}
