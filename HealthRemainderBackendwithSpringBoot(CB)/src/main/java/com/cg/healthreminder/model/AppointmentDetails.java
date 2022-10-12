/**
 * @SayantanDas
 * 
 * This is the Model/Entity Class for AppointmentDetails
*/

package com.cg.healthreminder.model;



import javax.persistence.*;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;


@Entity
@Table(name = "Appointment_Details")
public class AppointmentDetails {
	
	
	@Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "app_id")
    private int appId;
	
	@NotNull
	@Column
	@Min(1)
	private int patientId;
    
	@NotNull
	@Column
	@Min(1)
	private int doctorId;
	
	@NotNull
	@Column
	@Size(min = 3, max =30, message="Max length is 30" )
	@Pattern(regexp = "[A-Za-z]+",message="Please enter only Alphabets")
	private String doctorName;
	
	@NotNull
	@Column
	@Size(min = 3, max =30, message="Max length is 30" )
	@Pattern(regexp = "[A-Za-z]+",message="Please enter only Alphabets")
	private String patientName;
	
	@NotNull
	@Column
	private String doctorDate;
   
	@NotNull
    @Column
	private String doctorStartTime;
	
	@NotNull
	@Column
	private String doctorEndTime;

	public int getAppId() {
		return appId;
	}

	public void setAppId(int appId) {
		this.appId = appId;
	}

	public int getPatientId() {
		return patientId;
	}

	public void setPatientId(int patientId) {
		this.patientId = patientId;
	}

	public int getDoctorId() {
		return doctorId;
	}

	public void setDoctorId(int doctorId) {
		this.doctorId = doctorId;
	}

	public String getDoctorName() {
		return doctorName;
	}

	public void setDoctorName(String doctorName) {
		this.doctorName = doctorName;
	}

	public String getPatientName() {
		return patientName;
	}

	public void setPatientName(String patientName) {
		this.patientName = patientName;
	}

	public String getDoctorDate() {
		return doctorDate;
	}

	public void setDoctorDate(String doctorDate) {
		this.doctorDate = doctorDate;
	}

	public String getDoctorStartTime() {
		return doctorStartTime;
	}

	public void setDoctorStartTime(String doctorStartTime) {
		this.doctorStartTime = doctorStartTime;
	}

	public String getDoctorEndTime() {
		return doctorEndTime;
	}

	public void setDoctorEndTime(String doctorEndTime) {
		this.doctorEndTime = doctorEndTime;
	}

	@Override
	public String toString() {
		return "AppointmentDetails [appId=" + appId + ", patientId=" + patientId + ", doctorId=" + doctorId
				+ ", doctorName=" + doctorName + ", patientName=" + patientName + ", doctorDate=" + doctorDate
				+ ", doctorStartTime=" + doctorStartTime + ", doctorEndTime=" + doctorEndTime + "]";
	}


}
