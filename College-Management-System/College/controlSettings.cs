using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class controlSettings : UserControl
    {
        private static controlSettings _instance;
        public static controlSettings Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlSettings();
                }
                return _instance;
            }
        }
        public controlSettings()
        {
            InitializeComponent();
            loadSettings();
        }
        public void loadSettings()
        {
            try
            {
                txtExamFee.Text = College.App_Code.settings.examFee.ToString();
                txtFine.Text = College.App_Code.settings.fine.ToString();
                txtAnnualFund.Text = College.App_Code.settings.annualFund.ToString();
                txtAdmissionFee.Text = College.App_Code.settings.admissionFee.ToString();
                txtAddress.Text = College.App_Code.settings.address.ToString();
                txtPhone.Text = College.App_Code.settings.phone.ToString();
                txtEmail.Text = College.App_Code.settings.email.ToString();
                txtInstitute.Text = College.App_Code.settings.institute.ToString();
                txtMoto.Text = College.App_Code.settings.moto.ToString();
                txtCurrency.Text = College.App_Code.settings.currency.ToString();
                Image img1 = byteArrayToImage(College.App_Code.settings.logo);
                pictureBox6.Image = img1;

                Image img2 = byteArrayToImage(College.App_Code.settings.logoReport);
                pictureBox1.Image = img2;
            }
            catch (Exception ex)
            {

            }
        }
        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                double examFee = double.Parse(txtExamFee.Text);
                double fine = double.Parse(txtFine.Text);
                double annualFund = double.Parse(txtAnnualFund.Text);
                double admissionFee = double.Parse(txtAdmissionFee.Text);
                string address = txtAddress.Text;
                string phone = txtPhone.Text;
                string email = txtEmail.Text;
                string institute = txtInstitute.Text;
                string moto = txtMoto.Text;
                string currency = txtCurrency.Text;



                System.Drawing.Image imgx;
                //Create the image object
                Image ximgx = pictureBox6.Image;
                imgbytes = imageToByteArray(ximgx);

                Image ximgx2 = pictureBox1.Image;
                imgbytesReport = imageToByteArray(ximgx2);


                App_Code.settings obj = new App_Code.settings();
                obj.eFee = examFee;
                obj.eFine = fine;
                obj.aFund = annualFund;
                obj.adFund = admissionFee;
                obj.cAddress = address;
                obj.cPhone = phone;
                obj.cEmail = email;
                obj.iName = institute;
                obj.iMoto = moto;
                obj.Image = imgbytes;
                obj.ImageReport = imgbytesReport;
                obj.iCurrency = currency;
                obj.updateSettings();

                College.App_Code.settings sets = new College.App_Code.settings();
                DataTable dt = sets.getSettings();
                College.App_Code.settings.examFee = double.Parse(dt.Rows[0][1].ToString());
                College.App_Code.settings.fine = double.Parse(dt.Rows[0][2].ToString());
                College.App_Code.settings.annualFund = double.Parse(dt.Rows[0][3].ToString());
                College.App_Code.settings.admissionFee = double.Parse(dt.Rows[0][4].ToString());
                College.App_Code.settings.address = dt.Rows[0][5].ToString();
                College.App_Code.settings.phone = dt.Rows[0][6].ToString();
                College.App_Code.settings.email = dt.Rows[0][7].ToString();
                College.App_Code.settings.institute = dt.Rows[0][8].ToString();
                College.App_Code.settings.currency = dt.Rows[0][12].ToString();
                College.App_Code.settings.moto = dt.Rows[0][9].ToString();
                College.App_Code.settings.logo = (Byte[])dt.Rows[0][10];
                College.App_Code.settings.logoReport = (Byte[])dt.Rows[0][11];

                loadSettings();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        public byte[] imageToByteArray(System.Drawing.Image imageIn)
        {
            MemoryStream ms = new MemoryStream();
            imageIn.Save(ms, System.Drawing.Imaging.ImageFormat.Png);
            return ms.ToArray();
        }
        Byte[] imgbytes;
        private void pictureBox6_Click(object sender, EventArgs e)
        {
            OpenFileDialog obj = new OpenFileDialog();
            obj.Filter = "Image Files (*.png)|*.png";
            obj.FilterIndex = 1;
            DialogResult file = obj.ShowDialog();

            if (file == DialogResult.OK)
            {
                //labelpicture.Text = obj.SafeFileName;
                pictureBox6.Image = Image.FromFile(obj.FileName);
                this.imgbytes = imageToByteArray(Image.FromFile(obj.FileName));
            }
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }
        Byte[] imgbytesReport;

        private void report(object sender, EventArgs e)
        {
            OpenFileDialog obj = new OpenFileDialog();
            obj.Filter = "Image Files (*.png)|*.png";
            obj.FilterIndex = 1;
            DialogResult file = obj.ShowDialog();

            if (file == DialogResult.OK)
            {
                //labelpicture.Text = obj.SafeFileName;
                pictureBox1.Image = Image.FromFile(obj.FileName);
                this.imgbytesReport = imageToByteArray(Image.FromFile(obj.FileName));
            }
        }
    }
}
