using System;
using System.Data;
using System.Data.SqlClient;

namespace College.App_Code
{
    class Ledger
    {
        public int id { get; set; }
        public string type { get; set; }
        public double amount { get; set; }
        public string reason { get; set; }
        public string note { get; set; }
        public DateTime date { get; set; }


        public string month { get; set; }
        public int year { get; set; }


        DBConnection strcon = new DBConnection();
        public void updateLedger()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update ledger set type=@type,amount=@amount,date=@date,note=@note,reason=@reason where id='1'";
                cmd.Parameters.AddWithValue("@type", this.type);
                cmd.Parameters.AddWithValue("@amount", this.amount);
                cmd.Parameters.AddWithValue("@reason", this.reason);
                cmd.Parameters.AddWithValue("@date", this.date);
                cmd.Parameters.AddWithValue("@note", this.note);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update ledger data" + ex);
            }
        }
        public int addLedger()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "INSERT INTO ledger(type,amount,reason,date,note)"
                + "VALUES(@type,@amount,@reason,@date,@note)";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.Parameters.AddWithValue("@type", this.type);
                cmd.Parameters.AddWithValue("@amount", this.amount);
                cmd.Parameters.AddWithValue("@reason", this.reason);
                cmd.Parameters.AddWithValue("@date", this.date);
                cmd.Parameters.AddWithValue("@note", this.note);
                cmd.ExecuteNonQuery();
                cmd.CommandText = "SELECT @@IDENTITY";
                int value = Convert.ToInt32(cmd.ExecuteScalar());
                connection.Close();
                return value;
            }
            catch (Exception ex)
            {
                throw new Exception(ex.ToString());
            }
        }
        public DataTable getLedgerByDate()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT * from ledger where date='" + this.date + "'", connection))
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
                throw new Exception("Could not get ledger data");
            }
        }
        public DataTable getByMonth()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT * from ledger where datename(month,date)='" + this.month + "' and year(date)='" + this.year + "'", connection))
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
                throw new Exception("Could not get ledger data");
            }
        }
    }
}
