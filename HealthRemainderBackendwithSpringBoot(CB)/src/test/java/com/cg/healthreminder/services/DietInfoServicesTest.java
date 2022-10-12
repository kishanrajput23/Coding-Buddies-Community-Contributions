package com.cg.healthreminder.services;

import com.cg.healthreminder.dao.DietInfoJpaDao;
import com.cg.healthreminder.model.DietInfo;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

/**
 * @ParthGoel
 *
 * This is the test class for Diet Information services
 */

@RunWith(SpringRunner.class)
@SpringBootTest
public class DietInfoServicesTest {

    @MockBean
    private DietInfoJpaDao dietInfoJpaDao;

    @Autowired
    private DietInfoServices dietInfoServices;
    
    /**
	 * To test create diet information details
	 */
    @Test
    public void testCreateDiet(){
        DietInfo dietInfo = new DietInfo();
        dietInfo.setBmiValue(3);
        dietInfo.setDiet("Pizza, pizza, pizza");

        Mockito.when(dietInfoJpaDao.save(dietInfo)).thenReturn(dietInfo);
        assertThat(dietInfoServices.createDiet(dietInfo)).isEqualTo(dietInfo);
    }
    
//    @Test
//    public void testFindDietByBMI() throws Exception{
//        DietInfo dietInfo = new DietInfo();
//        dietInfo.setBmiValue(2);
//        dietInfo.setDietInfo("Burgers, Burgers, Burgers");
//        
//        DietInfo di=dietInfoJpaDao.findById(2).get();
//        Mockito.when(di).thenReturn(dietInfo);
//        assertThat(dietInfoServices.findDietByBMI(2)).isEqualTo(dietInfo);
//    }
    
    @Test
    public void testGetAllDiets() throws Exception{
        DietInfo di1 = new DietInfo();
        di1.setBmiValue(2);
        di1.setDiet("candy, candy, candy");

        DietInfo di2 = new DietInfo();
        di2.setBmiValue(3);
        di2.setDiet("pav, bhaji, butter");
        
        List<DietInfo> dietInfoList = new ArrayList<>();
        dietInfoList.add(di1);
        dietInfoList.add(di2);

        Mockito.when(dietInfoJpaDao.findAll()).thenReturn(dietInfoList);
        assertThat(dietInfoServices.getAllDiets()).isEqualTo(dietInfoList);
    
    }
    
//    @Test
//    public void testDeleteTicketById() throws Exception{
//        DietInfo dietInfo = new DietInfo();
//        dietInfo.setBmiValue(2);
//        dietInfo.setDietInfo("candy, candy, candy");
//        
//        Mockito.when(dietInfoJpaDao.save(dietInfo)).thenReturn(dietInfo);
//        Mockito.when(dietInfoJpaDao.findById(2).get()).thenReturn(dietInfo);
//        dietInfoJpaDao.deleteById(dietInfo.getBmiValue());
//        Mockito.when(dietInfoJpaDao.findById(2).get()).thenReturn(dietInfo);
//        Assert.assertNotEquals(dietInfo, new DietInfo());
//        Assert.assertEquals(dietInfoServices.deleteDietByBMI(2), false);
//    }

}
