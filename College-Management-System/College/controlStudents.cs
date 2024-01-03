using College.App_Code;
using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class controlStudents : UserControl
    {
        private static controlStudents _instance;
        public static controlStudents Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlStudents();
                }
                return _instance;
            }
        }

        public controlStudents()
        {
            InitializeComponent();
            try
            {
                loadBatchData();
                loadClasses();
                cboGender.SelectedIndex = 0;
                cboPercentage.SelectedIndex = 0;
                cboMaritalStatus.SelectedIndex = 0;
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
        private void button1_Click(object sender, System.EventArgs e)
        {

        }
        public byte[] imageToByteArray(System.Drawing.Image imageIn)
        {
            MemoryStream ms = new MemoryStream();
            imageIn.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
            return ms.ToArray();
        }
        private void submit(object sender, System.EventArgs e)
        {
            Byte[] currentPic;
            Byte[] imgbytes;
            try
            {
                if (txtRegistrationNo.Text == "-")  // fresh
                {
                    string name = (string.IsNullOrWhiteSpace(txtName.Text)) ? "" : txtName.Text;
                    string father = (string.IsNullOrWhiteSpace(txtFatherName.Text)) ? "" : txtFatherName.Text;
                    if (name.Length == 0 || father.Length == 0)
                    {
                        ErrorBox error = new ErrorBox();
                        error.ShowDialog();
                    }
                    else
                    {
                        int batchCode = Int32.Parse(((KeyValuePair<string, string>)cboBatch.SelectedItem).Key);
                        int cls = Int32.Parse(((KeyValuePair<string, string>)cboClass.SelectedItem).Key);
                        DateTime regDate = DateTime.Parse(txtRegDate.Value.ToShortDateString());
                        DateTime dob = DateTime.Parse(txtDob.Value.ToShortDateString());


                        string contactNumber = (string.IsNullOrWhiteSpace(txtContactNo.Text)) ? "" : txtContactNo.Text;
                        string gender = cboGender.Text;
                        string scholarship = cboPercentage.Text;
                        string maritalStatus = cboMaritalStatus.Text;
                        string nic = (string.IsNullOrWhiteSpace(txtNic.Text)) ? "" : txtNic.Text;
                        string email = (string.IsNullOrWhiteSpace(txtEmail.Text)) ? "" : txtEmail.Text;
                        string address = (string.IsNullOrWhiteSpace(txtAddress.Text)) ? "" : txtAddress.Text;

                        System.Drawing.Image imgx;
                        //Create the image object
                        Image ximgx = pictureBox6.Image;
                        imgbytes = imageToByteArray(ximgx);

                        Student obj = new Student();
                        obj.name = name;
                        obj.fatherName = father;
                        obj.contactNumber = contactNumber;
                        obj.gender = gender;
                        obj.maritalStatus = maritalStatus;
                        obj.nic = nic;
                        obj.email = email;
                        obj.address = address;
                        obj.registrationDate = regDate;
                        obj.dob = dob;
                        obj.image = imgbytes;
                        int xx = obj.getNextId();
                        obj.seriel = xx;
                        obj.batch = batchCode;
                        obj.classCode = cls;
                        obj.scholarship = Int32.Parse(scholarship);
                        //get class code by seriel
                        ClassList cl = new ClassList();
                        cl.seriel = cls;
                        string classCode = cl.getClassCode();
                        string ids;
                        if (xx < 10)
                            ids = classCode + "-00" + xx.ToString();
                        else if (xx < 100)
                            ids = classCode + "-0" + xx.ToString();
                        else
                            ids = classCode + "-" + xx.ToString();


                        obj.studentId = ids;
                        obj.addFreshStudent();

                        ////------------------------------
                        //Registration reg = new Registration();
                        //reg.studentId = ids;
                        //reg.className = cls;
                        //reg.section = sec;
                        //reg.timming = timing;
                        //reg.admissionFee = admission;
                        //reg.tuitionFee = tuitionFee;
                        //reg.scholarship = scholarship;
                        //reg.totalAmount = totalAmount;
                        //reg.termName = term;
                        //reg.date = DateTime.Now.ToShortDateString();
                        //reg.amountPaid = received;
                        //reg.reference = cboTeacher.Text;

                        //if (dues > 0)
                        //    reg.dues = true;
                        //reg.duesAmount = dues;
                        ////----------------------------------------------------------------------
                        //regId = reg.register();
                        ////-----------------------------------------------------------------------
                        //Ledger led = new Ledger();
                        //led.Reason = "Admission";
                        //led.Date = DateTime.Now.ToShortDateString();
                        //led.Month = DateTime.Now.ToString("MMMM");
                        //led.Year = Int32.Parse(DateTime.Now.ToString("yyyy"));
                        //led.Credit = received;
                        //led.Account = regId;
                        //led.term = term;
                        //led.Note = "New Admission";
                        //led.session = "Sesson One";
                        //led.insertCredit();
                        ////----------------------------------------------------------------------
                        //string[] type = { "Student's Receipt", "Teacher's Receipt" };
                        //for (int i = 0; i < 2; i++)
                        //{
                        //    tp = type[i];
                        //    if (chkPrint.Value == true)
                        //    {

                        //        //callPrinter();
                        //        Receipt rs = new Receipt(regId);
                        //        rs.ShowDialog();

                        //    }
                        //}
                        //resetData();
                        //this.Close();
                        Done d = new Done();
                        d.ShowDialog();
                        resetData();
                    }
                }
                else //update
                {
                    string studentId = txtRegistrationNo.Text;
                    string name = (string.IsNullOrWhiteSpace(txtName.Text)) ? "" : txtName.Text;
                    string father = (string.IsNullOrWhiteSpace(txtFatherName.Text)) ? "" : txtFatherName.Text;
                    if (name.Length == 0 || father.Length == 0)
                    {
                        ErrorBox error = new ErrorBox();
                        error.ShowDialog();
                    }
                    else
                    {
                        int batchCode = Int32.Parse(((KeyValuePair<string, string>)cboBatch.SelectedItem).Key);
                        int cls = Int32.Parse(((KeyValuePair<string, string>)cboClass.SelectedItem).Key);
                        DateTime regDate = DateTime.Parse(txtRegDate.Value.ToShortDateString());
                        DateTime dob = DateTime.Parse(txtDob.Value.ToShortDateString());


                        string contactNumber = (string.IsNullOrWhiteSpace(txtContactNo.Text)) ? "" : txtContactNo.Text;
                        string gender = cboGender.Text;
                        string scholarship = cboPercentage.Text;
                        string maritalStatus = cboMaritalStatus.Text;
                        string nic = (string.IsNullOrWhiteSpace(txtNic.Text)) ? "" : txtNic.Text;
                        string email = (string.IsNullOrWhiteSpace(txtEmail.Text)) ? "" : txtEmail.Text;
                        string address = (string.IsNullOrWhiteSpace(txtAddress.Text)) ? "" : txtAddress.Text;

                        System.Drawing.Image imgx;
                        //Create the image object
                        Image ximgx = pictureBox6.Image;
                        imgbytes = imageToByteArray(ximgx);

                        Student obj = new Student();
                        obj.studentId = studentId;
                        obj.name = name;
                        obj.fatherName = father;
                        obj.contactNumber = contactNumber;
                        obj.gender = gender;
                        obj.maritalStatus = maritalStatus;
                        obj.nic = nic;
                        obj.email = email;
                        obj.address = address;
                        obj.registrationDate = regDate;
                        obj.scholarship = Int32.Parse(scholarship);
                        obj.dob = dob;
                        obj.image = imgbytes;
                        int xx = obj.getNextId();
                        obj.seriel = xx;
                        obj.batch = batchCode;
                        obj.classCode = cls;
                        //get class code by seriel
                        ClassList cl = new ClassList();
                        cl.seriel = cls;
                        string classCode = cl.getClassCode();

                        obj.updateStudent();

                        ////------------------------------
                        //Registration reg = new Registration();
                        //reg.studentId = ids;
                        //reg.className = cls;
                        //reg.section = sec;
                        //reg.timming = timing;
                        //reg.admissionFee = admission;
                        //reg.tuitionFee = tuitionFee;
                        //reg.scholarship = scholarship;
                        //reg.totalAmount = totalAmount;
                        //reg.termName = term;
                        //reg.date = DateTime.Now.ToShortDateString();
                        //reg.amountPaid = received;
                        //reg.reference = cboTeacher.Text;

                        //if (dues > 0)
                        //    reg.dues = true;
                        //reg.duesAmount = dues;
                        ////----------------------------------------------------------------------
                        //regId = reg.register();
                        ////-----------------------------------------------------------------------
                        //Ledger led = new Ledger();
                        //led.Reason = "Admission";
                        //led.Date = DateTime.Now.ToShortDateString();
                        //led.Month = DateTime.Now.ToString("MMMM");
                        //led.Year = Int32.Parse(DateTime.Now.ToString("yyyy"));
                        //led.Credit = received;
                        //led.Account = regId;
                        //led.term = term;
                        //led.Note = "New Admission";
                        //led.session = "Sesson One";
                        //led.insertCredit();
                        ////----------------------------------------------------------------------
                        //string[] type = { "Student's Receipt", "Teacher's Receipt" };
                        //for (int i = 0; i < 2; i++)
                        //{
                        //    tp = type[i];
                        //    if (chkPrint.Value == true)
                        //    {

                        //        //callPrinter();
                        //        Receipt rs = new Receipt(regId);
                        //        rs.ShowDialog();

                        //    }
                        //}
                        //resetData();
                        //this.Close();
                        Done d = new Done();
                        d.ShowDialog();
                        resetData();
                    }
                }

            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        public void loadData()
        {
            string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
            Student std = new Student();
            std.studentId = stdId;
            DataTable dt = std.getStudentById();

            txtRegistrationNo.Text = dt.Rows[0][1].ToString();
            txtName.Text = dt.Rows[0][2].ToString();
            txtFatherName.Text = dt.Rows[0][3].ToString();
            txtRegDate.Value = DateTime.Parse(dt.Rows[0][4].ToString());
            txtContactNo.Text = dt.Rows[0][5].ToString();
            txtDob.Value = DateTime.Parse(dt.Rows[0][6].ToString());



            string gender = dt.Rows[0][7].ToString();

            int i = 0;
            foreach (string g in cboGender.Items)
            {
                if (g == gender)
                {
                    cboGender.SelectedIndex = i;
                }
                i++;
            }


            string percentage = dt.Rows[0][15].ToString();

            i = 0;
            foreach (string g in cboPercentage.Items)
            {
                if (g == percentage)
                {
                    cboPercentage.SelectedIndex = i;
                }
                i++;
            }


            string maritalStatus = dt.Rows[0][8].ToString();

            i = 0;
            foreach (string m in cboMaritalStatus.Items)
            {
                if (m == maritalStatus)
                {
                    cboMaritalStatus.SelectedIndex = i;
                }
                i++;
            }


            txtNic.Text = dt.Rows[0][9].ToString();
            txtEmail.Text = dt.Rows[0][10].ToString();
            txtAddress.Text = dt.Rows[0][11].ToString();
            int bCode = Int32.Parse(dt.Rows[0][13].ToString());

            int c = 0;
            for (int x = 0; x < cboBatch.Items.Count; x++)
            {

                int str = Int32.Parse(((KeyValuePair<string, string>)cboBatch.Items[x]).Key);
                if (str == bCode)
                {
                    cboBatch.SelectedIndex = c;
                    break;
                }
                c++;
            }





            int cCode = Int32.Parse(dt.Rows[0][14].ToString());
            c = 0;
            for (int x = 0; x < cboClass.Items.Count; x++)
            {

                int str = Int32.Parse(((KeyValuePair<string, string>)cboClass.Items[x]).Key);
                if (str == cCode)
                {
                    cboClass.SelectedIndex = c;
                    break;
                }
                c++;
            }
            this.imgbytes = (Byte[])dt.Rows[0][12];
            Image img1 = byteArrayToImage(this.imgbytes);
            pictureBox6.Image = img1;
        }
        private void textBox1_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                string search = txtSearch.Text;
                Student std = new Student();
                std.search = search;
                DataTable dt = std.searchSudent();
                studentGrid.DataSource = dt;
            }
            catch (Exception ex)
            {

            }
        }

        private void studentGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                loadData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }
        Byte[] imgbytes;

        private void button1_Click_1(object sender, EventArgs e)
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



        private void studentGrid_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                loadData();
            }
            catch (Exception ex)
            {

            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                YesNo y = new YesNo();
                y.ShowDialog();
                if (Common.command == true)
                {
                    string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
                    Student std = new Student();
                    std.studentId = stdId;
                    std.delete();
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void reset(object sender, EventArgs e)
        {
            resetData();
        }
        public void resetData()
        {
            txtRegistrationNo.Text = "-";
            cboGender.SelectedIndex = 0;
            cboMaritalStatus.SelectedIndex = 0;
            cboBatch.SelectedIndex = 0;
            txtAddress.Text = "";
            txtDob.Value = DateTime.Parse(DateTime.Now.ToShortDateString());
            txtRegDate.Value = DateTime.Parse(DateTime.Now.ToShortDateString());
            txtEmail.Text = "";
            txtFatherName.Text = "";
            txtName.Text = "";
            txtContactNo.Text = "";
            txtNic.Text = "";
            txtSearch.Text = "";
            pictureBox6.Image = College.Properties.Resources._default;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                GenerateFee obj = new GenerateFee();
                obj.ShowDialog();
            }
            catch (Exception ex)
            {
                ErrorBox error = new ErrorBox();
                error.ShowDialog();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            try
            {
                if (studentGrid.Rows.Count == 0)
                {
                    ErrorBox error = new ErrorBox();
                    error.ShowDialog();
                }
                else
                {
                    string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
                    PayFee obj = new PayFee(stdId);
                    obj.ShowDialog();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void panel4_Paint(object sender, PaintEventArgs e)
        {

        }

        private void singleprofile(object sender, EventArgs e)
        {
            try
            {
                string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
                ReportSingleStudentProfle obj = new ReportSingleStudentProfle(stdId);
                obj.ShowDialog();
            }
            catch (Exception ex)
            {

            }
        }


        private void ManageClasses2(object sender, EventArgs e)
        {
            ManageClasses obj = new ManageClasses();
            obj.ShowDialog();

            try
            {
                Done d = new Done();
                d.ShowDialog();
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

        private void batch(object sender, EventArgs e)
        {
            ManageBatch obj = new ManageBatch();
            obj.ShowDialog();

            try
            {
                Done d = new Done();
                d.ShowDialog();

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

        private void Qualification(object sender, EventArgs e)
        {
            try
            {
                string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
                ManageQualifications obj = new ManageQualifications(stdId, "Student");
                obj.ShowDialog();
            }
            catch (Exception ex)
            {

            }
        }

        private void at(object sender, EventArgs e)
        {
            try
            {
                MarkStudentAttendance obj = new MarkStudentAttendance();
                obj.ShowDialog();
            }
            catch (Exception ex)
            {

            }
        }

        private void vew(object sender, EventArgs e)
        {
            try
            {
                string stdId = studentGrid.SelectedRows[0].Cells[0].Value.ToString();
                ReportStudentAttendance obj = new ReportStudentAttendance(stdId);
                obj.ShowDialog();
            }
            catch (Exception ex)
            {

            }
        }

        private void ca(object sender, EventArgs e)
        {
            try
            {
                ReportClassAttendance obj = new ReportClassAttendance();
                obj.ShowDialog();
            }
            catch (Exception ex)
            {

            }
        }
    }
}
