
using System;
using System.Data;
using System.Data.SqlClient;
namespace College.App_Code
{
    class Qualification
    {
        public int seriel { get; set; }
        public string id { get; set; }
        public string degree { get; set; }
        public string institute { get; set; }
        public int year { get; set; }
        public string type { get; set; }
        DBConnection strcon = new DBConnection();
        public bool checkClass()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from qualification where degree='" + this.degree + "' and id='"+this.id+"'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        public void addQualifications()
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
                    string sql = "INSERT INTO qualification(id,degree,institute,year,type)"
                    + "VALUES(@id,@degree,@institute,@year,@type)";
                    SqlCommand cmd = new SqlCommand(sql, connection);
                    cmd.Parameters.AddWithValue("@id", this.id);
                    cmd.Parameters.AddWithValue("@degree", this.degree);
                    cmd.Parameters.AddWithValue("@institute", this.institute);
                    cmd.Parameters.AddWithValue("@year", this.year);
                    cmd.Parameters.AddWithValue("@type", this.type);
                    cmd.ExecuteNonQuery();
                    connection.Close();
                }
                catch (Exception ex)
                {
                    throw new Exception("Could not insert qualification data");
                }
            }

        }
        public void updateBatch()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update qualification set institute=@institute,year=@year where id='" + this.id + "' and degree='" + this.degree + "'";
                cmd.Parameters.AddWithValue("@institute", this.institute);
                cmd.Parameters.AddWithValue("@year", this.year);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update qualification data");
            }
        }
        public void delete()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from qualification Where id='" + this.id + "' and degree='" + this.degree + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete qualification data");
            }
        }
        public DataTable getSpecificQualification()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from qualification where id='" + this.id + "' and type='" + this.type + "'", connection))
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
                throw new Exception("Could not get qualification data");
            }
        }
    }
}
