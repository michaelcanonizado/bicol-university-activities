package org.PayrollForm;

public class Main {
    public static void main(String[] args) {
        FreelancerPayrollForm mikeyPayroll = new FreelancerPayrollForm("Mikey", 500);

        System.out.println("----------------------------------");
        mikeyPayroll.displayFreelancerInfo();
        System.out.println("Hourly Rate:" + mikeyPayroll.getHourlyRate() + "/hr");
        System.out.println("----------------------------------");
        mikeyPayroll.trackProjectPayment(8);
        mikeyPayroll.displayFreelancerInfo();
        mikeyPayroll.trackProjectPayment(3);
        mikeyPayroll.displayFreelancerInfo();
    }
}