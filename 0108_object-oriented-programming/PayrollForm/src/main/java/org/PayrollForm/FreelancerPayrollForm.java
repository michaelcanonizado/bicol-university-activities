package org.PayrollForm;

public class FreelancerPayrollForm {
    // Attributes
    private String freelancerName;
    private double hourlyRate;
    private double hoursWorked;
    private double grossIncome;

    // Constructor
    public FreelancerPayrollForm (String freelancerName, double hourlyRate) {
        this.freelancerName = freelancerName;
        this.hourlyRate = hourlyRate;

        this.hoursWorked = 0.0;
        this.grossIncome = 0.0;
    }

    // Utility Methods
    public double calculateProjectPayment(double hoursWorked) {
        return this.hoursWorked * hourlyRate;
    }
    public void trackProjectPayment(double hoursWorked) {
        double payment = calculateProjectPayment((hoursWorked));
        this.grossIncome += payment;
        this.hoursWorked += hoursWorked;
        System.out.println("Payment for this project: ₱" + payment);
        System.out.println("Updated Gross Income: ₱" + this.grossIncome);
        System.out.println("Updated Hours Worked: " + this.hoursWorked);
        System.out.println("----------------------------------");
    }
    public void displayFreelancerInfo() {
        System.out.println("Freelancer Information:");
        System.out.println("Name: " + this.freelancerName);
        System.out.println("Hours Worked: " + this.hoursWorked);
        System.out.println("Hourly Rate: ₱" + this.hourlyRate + "/hr");
        System.out.println("Gross Income: ₱" + this.grossIncome);
        System.out.println("----------------------------------");
    }

    // Accessor Methods
    public String getFreelancerName() {
        return freelancerName;
    }
    public double getHourlyRate() {
        return hourlyRate;
    }

    // Mutator Methods
    public void setFreelancerName(String freelancerName) {
        this.freelancerName = freelancerName;
    }
    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }
}
