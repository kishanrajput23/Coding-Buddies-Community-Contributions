package com.cg.healthreminder.services;

//@author Naman Bhandari

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.dao.MedicalHistoryDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MedicalHistory;

import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@SpringBootTest
public class MedicalHistoryServiceTest {
	@MockBean
    private MedicalHistoryDao medicalHistoryDao;

    @Autowired
    private MedicalHistoryService medicalHistoryService;
    
    @Test
    public void testCreateMedicalHistory() throws AllCustomException{
    	MedicalHistory mh = new MedicalHistory();
    	mh.setFile("file name");
    	mh.setPatientId(1);
    	mh.setNotes("sample notes");
    	
    	Mockito.when(medicalHistoryDao.save(mh)).thenReturn(mh);
	    assertThat(medicalHistoryService.addRecord(mh)).isEqualTo(mh);
    }
    
   /* @Test
    public void testUpdateRecord() throws Exception{
    	MedicalHistory mh = new MedicalHistory();
    	mh.setFile("file name");
    	mh.setPatientId(1);
    	mh.setNotes("sample notes");
    	
    	Mockito.when(medicalHistoryDao.save(mh)).thenReturn(mh);
    	mh.setNotes("new notes");
    	Mockito.when(medicalHistoryDao.save(mh)).thenReturn(mh);
    	assertThat(medicalHistoryService.getByPatientId(1)).isEqualTo(mh);
    	
    }*/
}
