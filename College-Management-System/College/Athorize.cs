using College.App_Code;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class Athorize : Form
    {
        public Athorize()
        {
            InitializeComponent();
            txtId.Select();
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
                string id = txtId.Text;
                string pwd = txtPwd.Text;
                pwd = StringCipher.Encrypt("collegedatabase", pwd);
                Employee emp = new Employee();
                emp.LoginId = id;
                emp.LoginPwd = pwd;
                bool x = emp.checkEmployeeLogin();
                if (x)
                {
                    string empid = emp.getEmpId();
                    emp.EmployeeId = empid;
                    string admin = emp.getCredentials();
                    Common.role = admin;
                    if (admin.Equals("Admin"))
                    {
                        Common.command = true;
                        this.Close();
                    }
                    else if (admin.Equals("Teacher"))
                    {
                        ErrorBox obj = new ErrorBox();
                        obj.ShowDialog();
                        Common.command = false;
                        this.Close();
                    }
                }
                else
                {
                    MessageBox.Show("Test");
                    ErrorBox obj = new ErrorBox();
                    obj.ShowDialog();
                    Common.command = false;
                    this.Close();
                }
            }
            catch (Exception ex)
            {
                //ErrorBox obj = new ErrorBox();
                //obj.ShowDialog();
                MessageBox.Show(ex.ToString());
            }
        }
    }
}
