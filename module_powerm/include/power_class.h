#ifndef POWER_CLASS_H_
#define POWER_CLASS_H_

#define BRIGHTNESS_P8 200
#define BRIGHTNESS_P7 200
#define BRIGHTNESS_P6 40
#define BRIGHTNESS_P5 30
#define BRIGHTNESS_P4 20
#define BRIGHTNESS_P3 10
#define BRIGHTNESS_P2 5
#define BRIGHTNESS_P1 3
#define BRIGHTNESS_P0 1

#define VIBRATOR_P6 30
#define VIBRATOR_P5 30
#define VIBRATOR_P4 30
#define VIBRATOR_P3 30
#define VIBRATOR_P2 30
#define VIBRATOR_P1 0
#define VIBRATOR_P0 0

#define MAX_CPUFREQ_P8 1958400
#define MAX_CPUFREQ_P7 1728000
#define MAX_CPUFREQ_P6 1574400
#define MAX_CPUFREQ_P5 1267200
#define MAX_CPUFREQ_P4 1190400
#define MAX_CPUFREQ_P3 1190400
#define MAX_CPUFREQ_P2 1036800
#define MAX_CPUFREQ_P1 1036800
#define MAX_CPUFREQ_P0 960000

#define MAX_GPU_LV_P8 1
#define MAX_GPU_LV_P7 1
#define MAX_GPU_LV_P6 2
#define MAX_GPU_LV_P5 3
#define MAX_GPU_LV_P4 3
#define MAX_GPU_LV_P3 4
#define MAX_GPU_LV_P2 4
#define MAX_GPU_LV_P1 5
#define MAX_GPU_LV_P0 5


struct power_class_ops
{
    void (*activate)(void);
};

struct power_class
{
    const struct power_class_ops *ops;
    int power_class_id;
};

// wrapper function
static inline void activate_power_class(struct power_class *p_class)
{
	p_class->ops->activate();
}

extern const struct power_class_ops *POWER_OPS_0;
extern const struct power_class_ops *POWER_OPS_1;
extern const struct power_class_ops *POWER_OPS_2;
extern const struct power_class_ops *POWER_OPS_3;
extern const struct power_class_ops *POWER_OPS_4;
extern const struct power_class_ops *POWER_OPS_5;
extern const struct power_class_ops *POWER_OPS_6;
extern const struct power_class_ops *POWER_OPS_7;
extern const struct power_class_ops *POWER_OPS_8;
extern const struct power_class_ops *POWER_OPS_X;

#endif
