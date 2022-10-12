/**
 * @AnkitBanerjee
 *
 * This is the Model/Entity class for Alarm Module
 */
package com.cg.healthreminder.model;

import java.sql.Date;
import java.sql.Timestamp;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;

import org.springframework.format.annotation.DateTimeFormat;

@Entity
@Table(name = "Alarm_Module")
public class AlarmModule {
	
	@Override
	public String toString() {
		return "AlarmModule [alarmId=" + alarmId + ", patientId=" + patientId + ", alarmName=" + alarmName
				+ ", alarmTime=" + alarmTime + ", alarmDate=" + alarmDate + ", alarmNotes=" + alarmNotes + "]";
	}
	
	@Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "alarm_id")
    private Integer alarmId;
	
	@NotNull
    @Column(name = "patient_id")
    private Integer patientId;
    
	@NotBlank(message = "Name is mandatory")
	@Size(min=2, max=30, message = "HEY User! try to put name size between 2 and 30")
    @Column(name = "alarm_name")
    private String alarmName;
    
	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @Column(name = "alarm_time", nullable = true)
    private Timestamp alarmTime;
    
	@DateTimeFormat(pattern = "yyyy-MM-dd")
    @Column(name = "alarm_date", nullable = true)
    private Date alarmDate;
    
    @NotNull
    @Size(min=2, max=50, message="please provide a message of size range between 2 to 50")
    @Column(name = "notes")
    private String alarmNotes;

	public Integer getAlarmId() {
		return alarmId;
	}

	public void setAlarmId(Integer alarmId) {
		this.alarmId = alarmId;
	}

	public Integer getPatientId() {
		return patientId;
	}

	public void setPatientId(Integer patientId) {
		this.patientId = patientId;
	}

	public String getAlarmName() {
		return alarmName;
	}

	public void setAlarmName(String alarmName) {
		this.alarmName = alarmName;
	}

	public Timestamp getAlarmTime() {
		return alarmTime;
	}

	public void setAlarmTime(Timestamp alarmTime) {
		this.alarmTime = alarmTime;
	}

	public Date getAlarmDate() {
		return alarmDate;
	}

	public void setAlarmDate(Date alarmDate) {
		this.alarmDate = alarmDate;
	}

	public String getAlarmNotes() {
		return alarmNotes;
	}

	public void setAlarmNotes(String alarmNotes) {
		this.alarmNotes = alarmNotes;
	}

	    
    
	
}
