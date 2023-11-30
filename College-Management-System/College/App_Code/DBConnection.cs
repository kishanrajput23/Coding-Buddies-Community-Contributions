
using System.Data.SqlClient;
namespace College.App_Code
{
    class DBConnection
    {
        SqlConnection connection;
        public DBConnection()
        {
            connection = new SqlConnection(@"data source=(local)\SQLEXPRESS;database=D:\PROJJECTS\COLLEGE\COLLEGE\COLLEGE\APP_DATA\COLLEGE.MDF; integrated security = SSPI");
            //connection = new SqlConnection(@"Data Source=192.168.0.10\SQLEXPRESS;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
            //connection = new SqlConnection(@"Data Source=192.168.10.50\SQLEXPRESS;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
            //            connection = new SqlConnection(@"Data Source=192.168.10.50,1433;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
            //connection = new SqlConnection(@"Data Source=(local)\SQLEXPRESS;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");



            // connection = new SqlConnection(@"Data Source=(local)\SQLEXPRESS;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
            //connection = new SqlConnection(@"Data Source=MCM-PC;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
            //connection = new SqlConnection(@"Data Source=ABBASALI-PC;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");


            // connection = new SqlConnection(@"Data Source=DESKTOP-VIQV0G5;Initial Catalog=D:\PROJJECTS\LANGUAGECENTER\LANGUAGECENTER\LANGUAGECENTER\DATACENTER.MDF;User ID=language;Password=language");
        }
        public SqlConnection connect()
        {
            connection.Open();

            return connection;
        }
        public void disconnect()
        {
            connection.Close();
        }
    }
}
