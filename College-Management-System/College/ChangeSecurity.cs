using College.App_Code;
using System;
using System.Windows.Forms;

namespace College
{
    public partial class ChangeSecurity : Form
    {
        public ChangeSecurity()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string id = (string.IsNullOrWhiteSpace(txtId.Text)) ? "" : txtId.Text;
                string idc = (string.IsNullOrWhiteSpace(txtIdConfirm.Text)) ? "" : txtIdConfirm.Text;
                if (id.Length == 0 || idc.Length == 0)
                {
                    ErrorBox er = new ErrorBox();
                    er.ShowDialog();
                }
                else
                {
                    if (id.Equals(idc))
                    {
                        Employee emp = new Employee();
                        emp.EmployeeId = Common.adminId;
                        emp.LoginId = id;
                        emp.updateLoginId();


                        Done d = new Done();
                        d.ShowDialog();
                        txtId.Text = "";
                        txtIdConfirm.Text = "";

                    }
                    else
                    {
                        ErrorBox er = new ErrorBox();
                        er.ShowDialog();
                    }
                }
            }
            catch (Exception ex)
            {
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string pwd = (string.IsNullOrWhiteSpace(txtPwd.Text)) ? "" : txtPwd.Text;
                string pwdc = (string.IsNullOrWhiteSpace(txtPwdConfirm.Text)) ? "" : txtPwdConfirm.Text;
                if (pwd.Length == 0 || pwdc.Length == 0)
                {
                    ErrorBox er = new ErrorBox();
                    er.ShowDialog();
                }
                else
                {
                    if (pwd.Equals(pwdc))
                    {
                        Employee emp = new Employee();
                        emp.EmployeeId = Common.adminId;
                        emp.LoginPwd = StringCipher.Encrypt("collegedatabase", pwd);
                        emp.updatePassword();
                        Done d = new Done();
                        d.ShowDialog();
                        txtPwd.Text = "";
                        txtPwdConfirm.Text = "";
                    }
                    else
                    {
                        ErrorBox er = new ErrorBox();
                        er.ShowDialog();
                    }
                }
            }
            catch (Exception ex)
            {
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
