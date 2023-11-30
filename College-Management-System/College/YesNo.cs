using System;
using System.Windows.Forms;

namespace College
{
    public partial class YesNo : Form
    {
        public YesNo()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            App_Code.Common.command = true;
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            App_Code.Common.command = false;
            this.Close();
        }
    }
}
