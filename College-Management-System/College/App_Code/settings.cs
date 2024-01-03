
using System;
using System.Data;
using System.Data.SqlClient;
namespace College.App_Code
{
    class settings
    {
        public double eFee { get; set; }
        public double eFine { get; set; }
        public double aFund { get; set; }
        public double adFund { get; set; }
        public string cAddress { get; set; }
        public string cPhone { get; set; }
        public string cEmail { get; set; }
        public string iName { get; set; }
        public string iMoto { get; set; }
        public string iCurrency { get; set; }
        //------------------------ Satic Values
        public static double examFee;
        public static double fine;
        public static double annualFund;
        public static double admissionFee;
        public static string address;
        public static string phone;
        public static string email;
        public static string currency;
        public static string institute;
        public static string moto;
        public static byte[] logo;
        public static byte[] logoReport;
        DBConnection strcon = new DBConnection();

        private byte[] image;

        public byte[] Image
        {
            get { return image; }
            set { image = value; }
        }

        private byte[] imageReport;

        public byte[] ImageReport
        {
            get { return imageReport; }
            set { imageReport = value; }
        }
        //------------------------------
        public DataTable getSettings()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from  settings", connection))
                {
                    DataSet ds = new DataSet();
                    ds1.Fill(ds);
                    DataTable dt = new DataTable();
                    dt = ds.Tables[0];
                    connection.Close();
                    return dt;
                }
            }
            catch (Exception ex)
            {
                throw new Exception(ex.ToString());
            }
        }
        public void updateSettings()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update settings set examFee=@examFee,fine=@fine,annualFund=@annualFund,admisionFee=@admissionFee,address=@address,phone=@phone,email=@email,institute=@institute,moto=@moto,image=@image,imageReport=@imageReport,currency=@currency where id='1'";
                cmd.Parameters.AddWithValue("@examFee", this.eFee);
                cmd.Parameters.AddWithValue("@fine", this.eFine);
                cmd.Parameters.AddWithValue("@annualFund", this.aFund);
                cmd.Parameters.AddWithValue("@admissionFee", this.adFund);
                cmd.Parameters.AddWithValue("@address", this.cAddress);
                cmd.Parameters.AddWithValue("@phone", this.cPhone);
                cmd.Parameters.AddWithValue("@email", this.cEmail);
                cmd.Parameters.AddWithValue("@institute", this.iName);
                cmd.Parameters.AddWithValue("@moto", this.iMoto);
                cmd.Parameters.AddWithValue("@image", this.image);
                cmd.Parameters.AddWithValue("@imageReport", this.imageReport);
                cmd.Parameters.AddWithValue("@currency", this.iCurrency);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update settings data" + ex);
            }
        }
    }
}
