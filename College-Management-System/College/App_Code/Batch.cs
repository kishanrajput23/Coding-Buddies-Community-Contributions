
using System;
using System.Data;
using System.Data.SqlClient;
namespace College.App_Code
{
    class Batch
    {
        public int seriel { get; set; }
        public string batchName { get; set; }
        DBConnection strcon = new DBConnection();
        public bool checkClass()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from batch where batchName='" + this.batchName + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        public void addClass()
        {
            bool x = this.checkClass();
            if (x)
            {
                //update
                updateBatch();
            }
            else
            {
                //insert
                try
                {
                    SqlConnection connection = strcon.connect();
                    string sql = "INSERT INTO batch(batchName)"
                    + "VALUES(@batchName)";
                    SqlCommand cmd = new SqlCommand(sql, connection);
                    cmd.Parameters.AddWithValue("@batchName", this.batchName);
                    cmd.ExecuteNonQuery();
                    connection.Close();
                }
                catch (Exception ex)
                {
                    throw new Exception("Could not insert batch data");
                }
            }

        }
        public void updateBatch()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update batch set batchName=@batchName where batchName='" + this.batchName + "'";
                cmd.Parameters.AddWithValue("@batchName", this.batchName);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update batch data");
            }
        }
        public void delete()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from batch Where seriel='" + this.seriel + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete batch data");
            }
        }
        public DataTable getAllBatches()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from batch order by seriel DESC", connection))
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
                throw new Exception("Could not get batch data");
            }
        }
        public string getBatchName()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = new SqlCommand("SELECT batchName from Batch where seriel='" + this.seriel + "'", connection);
                string value = cmd.ExecuteScalar().ToString();
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
