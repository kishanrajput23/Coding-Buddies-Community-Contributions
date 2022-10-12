package com.cg.healthreminder;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.CommandLineRunner;

import com.cg.healthreminder.dao.AppointmentDetailsJpaDao;
import com.cg.healthreminder.dao.AppointmentSlotsJpaDao;
import com.cg.healthreminder.dao.DiseaseJpaDao;
import com.cg.healthreminder.dao.MentalHealthJpaDao;
import com.cg.healthreminder.model.AppointmentDetails;
import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.model.Diseases;
import com.cg.healthreminder.model.MentalHealth;
import com.cg.healthreminder.model.SlotCompositeKey;

@SpringBootApplication
public class HealthreminderApplication implements CommandLineRunner{

	public static void main(String[] args) {
		SpringApplication.run(HealthreminderApplication.class, args);
	}
	
	 @Autowired
	    private DiseaseJpaDao diseaseJpaDao;
	 @Autowired
	 	private MentalHealthJpaDao mentalJpaDao;
	 @Autowired
	 	private AppointmentDetailsJpaDao appdetJpaDao;
	 @Autowired
	 	private AppointmentSlotsJpaDao appslotJpaDao;

	 
	    @Override
	    public void run(String...args) throws Exception {
	    	Diseases d=new Diseases();
			 d.setDiseaseId(1);
			 d.setDiseaseName("Cough");
			 d.setDiseaseInfo("Throat Irritation");
			 d.setDiseaseKeys("cough");
	        this.diseaseJpaDao.save(d);
	        
	        MentalHealth m=new MentalHealth();
			  m.setMentalRating(5);
			  m.setMentalTip("You need to eat chocolate");
			 this.mentalJpaDao.save(m);
			 
			 AppointmentDetails a= new AppointmentDetails();
			  a.setDoctorId(5);
			  a.setDoctorName("DoctorAstin");
			  a.setDoctorStartTime("12:00");
			  a.setDoctorEndTime("9:00");
			  a.setDoctorDate("12-05-2020"); 
			  a.setPatientName("Sayantan");
			  a.setPatientId(4);
			  this.appdetJpaDao.save(a);
			  
			  AppointmentSlots slot= new AppointmentSlots();
			  slot.setDoctorEndTime("12:00");
			  slot.setDoctorStartTime("9:00");
			  slot.setDoctorName("Naman");
			  SlotCompositeKey pk=new SlotCompositeKey();
			  pk.setDoctorDate("12-16-2020");
			  pk.setDoctorId(1);
			  slot.setPk(pk);
			  this.appslotJpaDao.save(slot);
	    }
}