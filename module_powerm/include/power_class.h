#ifndef POWER_CLASS_H_
#define POWER_CLASS_H_

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