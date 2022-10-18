using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class controlDashboard : UserControl
    {
        private static controlDashboard _instance;
        public static controlDashboard Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlDashboard();
                }
                return _instance;
            }
        }
        public controlDashboard()
        {
            InitializeComponent();
            loadImage();
        }
        Byte[] imgbytes;
        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }
        public void loadImage()
        {
            try
            {
                College.App_Code.settings sets = new College.App_Code.settings();
                DataTable dt = sets.getSettings();
                College.App_Code.settings.logo = (Byte[])dt.Rows[0][10];

                this.imgbytes = College.App_Code.settings.logo;
                Image img1 = byteArrayToImage(this.imgbytes);

                pictureBox1.Image = img1;
            }
            catch (System.Exception ex)
            {

            }
        }
    }
}
