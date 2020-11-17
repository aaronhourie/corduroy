top_height = 1.5;

color([1, 1, 0.0])
translate([0, 0, 4])
union() 
{
    difference() {
       cube([16, 8, top_height]);
       
       // Cut cube out of bottom
       translate([0.5, 0.5, -0.5])
        cube([15, 7, top_height]);
        
       // Cut cube out for OLED
       translate([5.5, 1, 0.5])
        cube([5, 3, 4]);
        
       // Cut cylinders out of top
       for (i = [0:3]) {
        translate([10.5 - (i*1.75), 6.25, top_height])
        cylinder(r=0.5, h=2, center=true,$fn=50);
       }
       
        for (i = [0:8]) {
            translate([-0.1, 0.1 + i*0.5, top_height - 0.25])
            cube([4, 0.2, top_height + 1]);
        }

    }
    
    // Legs
    translate([0.1, 0.1, -0.35])
        cube([0.25, 0.25, 0.5]);
    
    translate([15.65, 0.1, -0.35])
        cube([0.25, 0.25, 0.5]);
    
    translate([15.65, 7.65, -0.35])
        cube([0.25, 0.25, 0.5]);
    
    translate([0.1, 7.65, -0.35])
        cube([0.25, 0.25, 0.5]);


    translate([15.8, 0.8, top_height]) 
    linear_extrude(height=0.1)
    rotate([0, 0, 180])
    scale([0.05, 0.05, 0.4]) 
    {
        //text("\u5468\u6ce2\u6570\u5909\u8abf", font="SimSun:style=Black");
        
        text("Frequency Modulation");

    }


    {
       labels = ["1", "2", "3", "4"];
       for (i = [0:7]) {
        translate([10.6 - (i*1.75), 7.75, top_height])
        linear_extrude(height=0.1)
        scale([0.05, 0.05, 0.4]) 
        rotate([0, 0, 180])
        text(labels[i]);
       }
    }
}

bottom_height = 3.5;

color([0.3, 0.3, 0.3])
union() {
    
    difference() {
       cube([16, 8, bottom_height]);
       
       // Cut cube out of top
       translate([0.5, 0.5, 0.5])
        cube([15, 7, bottom_height]);
           // Cut cube out of top
        
       translate([-0.5, 1.5, 1])
        cube([2, 2, 2]);
        
       translate([0.0, 6., 1.5])
       rotate([0, 90, 0])
        cylinder(r=0.25, h=2, center=true,$fn=50);
        
        
            // Legs
    translate([0.08, 0.08, 2.85])
        cube([0.29, 0.29, 0.75]);
    
    translate([15.63, 0.08, 2.85])
        cube([0.29, 0.29, 0.75]);
    
    translate([15.63, 7.63, 2.85])
        cube([0.29, 0.29, 0.75]);
    
    translate([0.08, 7.63, 2.85])
        cube([0.29, 0.29, 0.75]);
    }
    
    rotate([0, 270, 0])
    rotate([0, 0, 270])
    linear_extrude(height=0.1)
    translate([-7.25, 0.5, 1])
    scale(0.04, 0.4, 0.04)
    {
        text("LINE OUT");
    }

    rotate([0, 270, 0])
    rotate([0, 0, 270])
    linear_extrude(height=0.1)
    translate([-3.4, 0.5, 1])
    scale(0.04, 0.4, 0.04)
    {
        text("MIDI IN");
    }
}
