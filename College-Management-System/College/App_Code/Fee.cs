using System;
using System.Data;
using System.Data.SqlClient;

namespace College.App_Code
{
    class Fee
    {
        public string seriel { get; set; }
        public string studentId { get; set; }
        public string month { get; set; }
        public int year { get; set; }
        public double admissionFee { get; set; }
        public double discount { get; set; }
        public double tuitionFee { get; set; }
        public double examFee { get; set; }
        public double fine { get; set; }
        public double annualFund { get; set; }
        public double totalAmount { get; set; }
        public int ledgerCode { get; set; }
        public bool received { get; set; }
        public DateTime receivingDate { get; set; }
        public string receivedBy { get; set; }
        DBConnection strcon = new DBConnection();

        public void pay()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update fee set  admissionFee=@admissionFee,fine=@fine,received='True',receivingDate=@receivingDate,totalAmount=@totalAmount,receivedBy=@receivedBy,ledgerCode=@ledgerCode where studentId='" + this.studentId + "' and month='" + this.month + "' and year='" + this.year + "'";
                cmd.Parameters.AddWithValue("@fine", this.fine);
                cmd.Parameters.AddWithValue("@admissionFee", this.admissionFee);
                cmd.Parameters.AddWithValue("@receivingDate", this.receivingDate);
                cmd.Parameters.AddWithValue("@totalAmount", this.totalAmount);
                cmd.Parameters.AddWithValue("@receivedBy", this.receivedBy);
                cmd.Parameters.AddWithValue("@ledgerCode", this.ledgerCode);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update fee data" + ex);
            }
        }
        public int check()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = new SqlCommand("SELECT count(*) from Fee where studentId='" + this.studentId + "' AND month='" + this.month + "' AND year='" + this.year + "'", connection);
                int value = Convert.ToInt32(cmd.ExecuteScalar());
                connection.Close();
                return value;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not count data" + ex);
            }
        }

        public void generateFee()
        {
            try
            {
                //check if exists 
                int x = check();
                if (x > 0)
                {
                }
                else//else insertNew
                {
                    SqlConnection connection = strcon.connect();
                    string sql = "INSERT INTO fee(seriel,studentId,month,year,tuitionFee,examFee,annualFund,fine,totalAmount,received,receivingDate,receivedBy,admissionFee,discount,ledgerCode)"
                    + "VALUES(@seriel,@studentId,@month,@year,@tuitionFee,@examFee,@annualFund,@fine,@totalAmount,@received,@receivingDate,@receivedBy,@admissionFee,@discount,@ledgerCode)";
                    SqlCommand cmd = new SqlCommand(sql, connection);
                    cmd.Parameters.AddWithValue("@seriel", this.seriel);
                    cmd.Parameters.AddWithValue("@studentId", this.studentId);
                    cmd.Parameters.AddWithValue("@month", this.month);
                    cmd.Parameters.AddWithValue("@year", this.year);
                    cmd.Parameters.AddWithValue("@tuitionFee", this.tuitionFee);
                    cmd.Parameters.AddWithValue("@examFee", this.examFee);
                    cmd.Parameters.AddWithValue("@annualFund", this.annualFund);
                    cmd.Parameters.AddWithValue("@fine", this.fine);
                    cmd.Parameters.AddWithValue("@totalAmount", this.totalAmount);
                    cmd.Parameters.AddWithValue("@received", this.received);
                    cmd.Parameters.AddWithValue("@receivingDate", this.receivingDate);
                    cmd.Parameters.AddWithValue("@receivedBy", this.receivedBy);
                    cmd.Parameters.AddWithValue("@admissionFee", this.admissionFee);
                    cmd.Parameters.AddWithValue("@discount", this.discount);
                    cmd.Parameters.AddWithValue("@ledgerCode", -1);
                    cmd.ExecuteNonQuery();
                    connection.Close();
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Could not insert new data" + ex);
            }
        }
        public DataTable getAllUnpaid()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT month as Month,year as Year,discount as Discount,tuitionFee as Tuition,examFee as Exam,admissionFee as [Admission],annualFund as Annual,fine as Fine, totalAmount as Total from fee where studentId='" + this.studentId + "' and received='False'", connection))
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
                throw new Exception("Could not get fee data");
            }
        }

        public double getTotaAmount()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = new SqlCommand("SELECT sum(totalAmount) as totalAmount from Fee where studentId='" + this.studentId + "' and received='False'", connection);
                double value = Convert.ToDouble(cmd.ExecuteScalar());
                connection.Close();
                return value;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not count data" + ex);
            }
        }
    }
}
