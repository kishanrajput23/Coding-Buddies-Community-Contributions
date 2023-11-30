using College.App_Code;
using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class controlStaff : UserControl
    {
        private static controlStaff _instance;
        public static controlStaff Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlStaff();
                }
                return _instance;
            }
        }
        public controlStaff()
        {
            InitializeComponent();
            bindGrid();
        }
        public byte[] imageToByteArray(System.Drawing.Image imageIn)
        {
            MemoryStream ms = new MemoryStream();
            imageIn.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
            return ms.ToArray();
        }
        Byte[] imgbytes;
        private void pictureBox6_Click(object sender, EventArgs e)
        {
            OpenFileDialog obj = new OpenFileDialog();
            obj.Filter = "Image Files (*.jpg)|*.jpg";
            obj.FilterIndex = 1;
            DialogResult file = obj.ShowDialog();

            if (file == DialogResult.OK)
            {
                //labelpicture.Text = obj.SafeFileName;
                pictureBox6.Image = Image.FromFile(obj.FileName);
                this.imgbytes = imageToByteArray(Image.FromFile(obj.FileName));
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Byte[] imgbytes;
            try
            {
                string empId = (string.IsNullOrWhiteSpace(txtEmployeeId.Text)) ? "" : txtEmployeeId.Text;
                string empName = (string.IsNullOrWhiteSpace(txtEmployeeName.Text)) ? "Not Provided" : txtEmployeeName.Text;
                string empEmail = (string.IsNullOrWhiteSpace(txtEmployeeEmail.Text)) ? "Not Provided" : txtEmployeeEmail.Text;
                string empPhone = (string.IsNullOrWhiteSpace(txtEmployeePhone.Text)) ? "Not Provided" : txtEmployeePhone.Text;
                double empBasicSalary = double.Parse((string.IsNullOrWhiteSpace(txtEmployeeBasicSalary.Text)) ? "0.0" : txtEmployeeBasicSalary.Text);
                string empAddress = (string.IsNullOrWhiteSpace(txtEmployeeAddress.Text)) ? "Not Provided" : txtEmployeeAddress.Text;
                string empDesignation = cboDesig.Text;
                string userRole = cboLoginRole.Text;
                bool active;
                if (activeSwitch.Checked)
                {
                    active = true;
                }
                else
                {
                    active = false;
                }

                System.Drawing.Image imgx;
                //Create the image object
                Image ximgx = pictureBox6.Image;


                imgbytes = imageToByteArray(ximgx);


                Employee emp = new Employee();
                emp.EmployeeId = empId;
                emp.EmployeeName = empName;
                emp.Email = empEmail;
                emp.designation2 = userRole;
                emp.PhoneNo = empPhone;
                emp.BasicSalary = empBasicSalary;
                emp.Address = empAddress;
                emp.Designation = empDesignation;
                emp.Active = active;
                //---------------------
                emp.LoginId = empId;
                emp.LoginPwd = StringCipher.Encrypt("collegedatabase", empId);
                emp.Image = imgbytes;
                emp.insertEmployee();

                Done d = new Done();
                d.ShowDialog();

                bindGrid();
                resetData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                //ErrorBox obj = new ErrorBox("Error uploading data to database. \n Please check your input.");
                //obj.ShowDialog();
            }

        }
        public void bindGrid()
        {
            try
            {
                Employee obj = new Employee();
                DataTable dt = obj.getAllEmployee();
                employeeGrid.DataSource = dt;
            }
            catch (Exception ex)
            {
                ErrorBox obj = new ErrorBox();
                obj.ShowDialog();
            }
        }
        public void resetData()
        {
            txtEmployeeAddress.Text = "";
            txtEmployeeBasicSalary.Text = "";
            txtEmployeeEmail.Text = "";
            txtEmployeeId.Text = "";
            txtEmployeeName.Text = "";
            txtEmployeePhone.Text = "";
            pictureBox6.Image = College.Properties.Resources._default;
        }

        private void delete(object sender, EventArgs e)
        {
            try
            {
                string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();
                Employee obj = new Employee();
                obj.EmployeeId = empId;
                YesNo ays = new YesNo();
                ays.ShowDialog();
                if (Common.command == true)
                {
                    obj.deleteEmployee();

                }
                resetData();
                bindGrid();
            }
            catch (Exception ex)
            {
                ErrorBox obj = new ErrorBox();
                obj.ShowDialog();
            }
        }

        private void employeeGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                if (employeeGrid.Rows.Count == 0)
                {
                    ErrorBox error = new ErrorBox();
                    error.ShowDialog();
                }
                else
                {
                    loadData();
                }
            }
            catch (Exception ex)
            {

            }
        }
        public void loadData()
        {
            try
            {
                string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();
                DataTable dt = new DataTable();
                Employee obj = new Employee();
                obj.EmployeeId = empId;
                dt = obj.getAllEmployeeById();
                txtEmployeeId.Text = dt.Rows[0][0].ToString();
                txtEmployeeName.Text = dt.Rows[0][1].ToString();
                txtEmployeeEmail.Text = dt.Rows[0][2].ToString();
                txtEmployeePhone.Text = dt.Rows[0][3].ToString();
                txtEmployeeAddress.Text = dt.Rows[0][4].ToString();
                txtEmployeeBasicSalary.Text = dt.Rows[0][6].ToString();
                bool x = bool.Parse(dt.Rows[0][10].ToString());
                int count = 0;
                foreach (string li in cboDesig.Items)
                {
                    if (li == dt.Rows[0][9].ToString())
                    {
                        cboDesig.SelectedIndex = count;
                    }
                    count++;
                }
                count = 0;
                foreach (string li in cboLoginRole.Items)
                {
                    if (li == dt.Rows[0][11].ToString())
                    {
                        cboLoginRole.SelectedIndex = count;
                    }
                    count++;
                }
                if (string.IsNullOrEmpty(dt.Rows[0][5].ToString()))
                {
                    pictureBox6.Image = College.Properties.Resources._default;
                }
                else
                {
                    this.imgbytes = (Byte[])dt.Rows[0][5];
                    Image img1 = byteArrayToImage(this.imgbytes);
                    pictureBox6.Image = img1;
                }
                if (x)
                {
                    activeSwitch.Checked = true;
                }
                else
                {
                    activeSwitch.Checked = false;
                }

            }
            catch (Exception ex)
            {
                //throw new Exception("Sorry");
            }
        }
        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }

        private void pay(object sender, EventArgs e)
        {
            try
            {
                string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();



                PaySalary obj = new PaySalary(empId);
                obj.ShowDialog();

            }
            catch (Exception ex)
            {
                ErrorBox obj = new ErrorBox();
                obj.ShowDialog();
            }
        }

        private void resetsecurity(object sender, EventArgs e)
        {
            try
            {
                string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();
                Employee obj = new Employee();
                obj.EmployeeId = empId;
                YesNo ays = new YesNo();
                ays.ShowDialog();
                if (Common.command == true)
                {
                    obj.LoginId = empId;
                    obj.LoginPwd = StringCipher.Encrypt("collegedatabase", empId);
                    obj.reset();
                    Done d = new Done();
                    d.ShowDialog();
                }
                resetData();
                bindGrid();
            }
            catch (Exception ex)
            {
                ErrorBox obj = new ErrorBox();
                obj.ShowDialog();
            }
        }

        private void q(object sender, EventArgs e)
        {
            string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();
            ManageQualifications obj = new ManageQualifications(empId, "Staff");
            obj.ShowDialog();
        }

        private void profile(object sender, EventArgs e)
        {
            string empId = employeeGrid.SelectedRows[0].Cells[0].Value.ToString();
            ReportStaffProfile obj = new ReportStaffProfile(empId);
            obj.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            resetData();
        }
    }
}
