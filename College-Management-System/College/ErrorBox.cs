using System;
using System.Windows.Forms;

namespace College
{
    public partial class ErrorBox : Form
    {
        public ErrorBox()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
