/*
 * Copyright (c) 2006-2022, Synwit Technology Co.,Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-10     Zohar_Lee    first version
 * 2020-07-10     lik          format file
 */

#include "drv_pwm.h"

#ifdef RT_USING_PWM
#ifdef BSP_USING_PWM

//#define DRV_DEBUG
#define LOG_TAG "drv.pwm"
#include <drv_log.h>

#if !defined(BSP_USING_PWM0) && !defined(BSP_USING_PWM1) && !defined(BSP_USING_PWM2) && !defined(BSP_USING_PWM3) && !defined(BSP_USING_PWM4) && !defined(BSP_USING_PWM5)
#error "Please define at least one BSP_USING_PWMx"
/* this driver can be disabled at menuconfig ? RT-Thread Components ? Device Drivers */
#endif

#define MIN_PERIOD 2
#define MIN_PULSE 1

#ifdef BSP_USING_PWM0
#ifndef PWM0_CFG
#define PWM0_CFG                                \
    {                                           \
        .name = "pwm0",                         \
        .PWMx = PWM0,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM0_CFG */
#endif /* BSP_USING_PWM0 */

#ifdef BSP_USING_PWM1
#ifndef PWM1_CFG
#define PWM1_CFG                                \
    {                                           \
        .name = "pwm1",                         \
        .PWMx = PWM1,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM1_CFG */
#endif /* BSP_USING_PWM1 */

#ifdef BSP_USING_PWM2
#ifndef PWM2_CFG
#define PWM2_CFG                                \
    {                                           \
        .name = "pwm2",                         \
        .PWMx = PWM2,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM2_CFG */
#endif /* BSP_USING_PWM2 */

#ifdef BSP_USING_PWM3
#ifndef PWM3_CFG
#define PWM3_CFG                                \
    {                                           \
        .name = "pwm3",                         \
        .PWMx = PWM3,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM3_CFG */
#endif /* BSP_USING_PWM3 */

#ifdef BSP_USING_PWM4
#ifndef PWM4_CFG
#define PWM4_CFG                                \
    {                                           \
        .name = "pwm4",                         \
        .PWMx = PWM4,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM4_CFG */
#endif /* BSP_USING_PWM4 */

#ifdef BSP_USING_PWM5
#ifndef PWM5_CFG
#define PWM5_CFG                                \
    {                                           \
        .name = "pwm5",                         \
        .PWMx = PWM5,                           \
        .pwm_initstruct.clk_div = PWM_CLKDIV_8, \
        .pwm_initstruct.mode = PWM_MODE_INDEP,  \
        .pwm_initstruct.cycleA = 10000,         \
        .pwm_initstruct.hdutyA = 5000,          \
        .pwm_initstruct.initLevelA = 1,         \
        .pwm_initstruct.cycleB = 10000,         \
        .pwm_initstruct.hdutyB = 5000,          \
        .pwm_initstruct.initLevelB = 1,         \
        .pwm_initstruct.HEndAIEn = 0,           \
        .pwm_initstruct.NCycleAIEn = 0,         \
        .pwm_initstruct.HEndBIEn = 0,           \
        .pwm_initstruct.NCycleBIEn = 0,         \
    }
#endif /* PWM5_CFG */
#endif /* BSP_USING_PWM5 */

struct swm_pwm_cfg
{
    const char *name;
    PWM_TypeDef *PWMx;
    PWM_InitStructure pwm_initstruct;
};

struct swm_pwm_device
{
    struct swm_pwm_cfg *pwm_cfg;
    struct rt_device_pwm pwm_device;
};

static struct swm_pwm_cfg swm_pwm_cfg[] =
    {
#ifdef BSP_USING_PWM0
        PWM0_CFG,
#endif
#ifdef BSP_USING_PWM1
        PWM1_CFG,
#endif
#ifdef BSP_USING_PWM2
        PWM2_CFG,
#endif
#ifdef BSP_USING_PWM3
        PWM3_CFG,
#endif
#ifdef BSP_USING_PWM4
        PWM4_CFG,
#endif
#ifdef BSP_USING_PWM5
        PWM5_CFG,
#endif
};

static struct swm_pwm_device pwm_obj[sizeof(swm_pwm_cfg) / sizeof(swm_pwm_cfg[0])] = {0};

static rt_err_t swm_pwm_enable(struct rt_device_pwm *pwm_device, struct rt_pwm_configuration *configuration, rt_bool_t enable)
{
    struct swm_pwm_cfg *pwm_cfg = RT_NULL;
    RT_ASSERT(pwm_device != RT_NULL);
    pwm_cfg = pwm_device->parent.user_data;

    if (!enable)
    {
        if (PWM_CH_A == configuration->channel)
        {
            PWM_Stop(pwm_cfg->PWMx, 1, 0);
        }
        if (PWM_CH_B == configuration->channel)
        {
            PWM_Stop(pwm_cfg->PWMx, 0, 1);
        }
    }
    else
    {
        if (PWM_CH_A == configuration->channel)
        {
            PWM_Start(pwm_cfg->PWMx, 1, 0);
        }
        if (PWM_CH_B == configuration->channel)
        {
            PWM_Start(pwm_cfg->PWMx, 0, 1);
        }
    }

    return RT_EOK;
}

static rt_err_t swm_pwm_get(struct rt_device_pwm *pwm_device, struct rt_pwm_configuration *configuration)
{
    rt_uint64_t tim_clock;
    tim_clock = SystemCoreClock / 8;

    struct swm_pwm_cfg *pwm_cfg = RT_NULL;
    RT_ASSERT(pwm_device != RT_NULL);
    pwm_cfg = pwm_device->parent.user_data;

    /* Convert nanosecond to frequency and duty cycle. 1s = 1 * 1000 * 1000 * 1000 ns */
    tim_clock /= 1000000UL;
    configuration->period = PWM_GetCycle(pwm_cfg->PWMx, configuration->channel) * 1000UL / tim_clock;
    configuration->pulse = PWM_GetHDuty(pwm_cfg->PWMx, configuration->channel) * 1000UL / tim_clock;

    return RT_EOK;
}

static rt_err_t swm_pwm_set(struct rt_device_pwm *pwm_device, struct rt_pwm_configuration *configuration)
{
    rt_uint32_t period, pulse;
    rt_uint64_t tim_clock;
    tim_clock = SystemCoreClock / 8;

    struct swm_pwm_cfg *pwm_cfg = RT_NULL;
    RT_ASSERT(pwm_device != RT_NULL);
    pwm_cfg = pwm_device->parent.user_data;

    /* Convert nanosecond to frequency and duty cycle. 1s = 1 * 1000 * 1000 * 1000 ns */
    /* when SystemCoreClock = 120MHz, configuration->period max 4.369ms */
    /* when SystemCoreClock = 20MHz, configuration->period max 26.214ms */
    tim_clock /= 1000000UL;
    period = (unsigned long long)configuration->period * tim_clock / 1000ULL;
    pulse = (unsigned long long)configuration->pulse * tim_clock / 1000ULL;
    if (period < MIN_PERIOD)
    {
        period = MIN_PERIOD;
    }
    if (pulse < MIN_PULSE)
    {
        pulse = MIN_PULSE;
    }
    PWM_SetCycle(pwm_cfg->PWMx, configuration->channel, period);
    PWM_SetHDuty(pwm_cfg->PWMx, configuration->channel, pulse);

    return RT_EOK;
}

static rt_err_t swm_pwm_control(struct rt_device_pwm *pwm_device, int cmd, void *arg)
{
    RT_ASSERT(pwm_device != RT_NULL);

    struct rt_pwm_configuration *configuration = (struct rt_pwm_configuration *)arg;

    switch (cmd)
    {
    case PWM_CMD_ENABLE:
        return swm_pwm_enable(pwm_device, configuration, RT_TRUE);
    case PWM_CMD_DISABLE:
        return swm_pwm_enable(pwm_device, configuration, RT_FALSE);
    case PWM_CMD_SET:
        return swm_pwm_set(pwm_device, configuration);
    case PWM_CMD_GET:
        return swm_pwm_get(pwm_device, configuration);
    default:
        return -RT_EINVAL;
    }
}

static struct rt_pwm_ops pwm_ops =
    {
        swm_pwm_control};

int swm_pwm_init(void)
{
    int i = 0;
    int result = RT_EOK;

    for (i = 0; i < sizeof(swm_pwm_cfg) / sizeof(swm_pwm_cfg[0]); i++)
    {
        pwm_obj[i].pwm_cfg = &swm_pwm_cfg[i];

        if (pwm_obj[i].pwm_cfg->PWMx == PWM0)
        {
#ifdef BSP_USING_PWM0A
            PORT_Init(PORTC, PIN2, FUNMUX0_PWM0A_OUT, 0);
#endif
#ifdef BSP_USING_PWM0B
            PORT_Init(PORTC, PIN4, FUNMUX0_PWM0B_OUT, 0);
#endif
        }
        else if (pwm_obj[i].pwm_cfg->PWMx == PWM1)
        {
#ifdef BSP_USING_PWM1A
            PORT_Init(PORTC, PIN3, FUNMUX1_PWM1A_OUT, 0);
#endif
#ifdef BSP_USING_PWM1B
            PORT_Init(PORTC, PIN5, FUNMUX1_PWM1B_OUT, 0);
#endif
        }
        else if (pwm_obj[i].pwm_cfg->PWMx == PWM2)
        {
#ifdef BSP_USING_PWM2A
            PORT_Init(PORTN, PIN4, FUNMUX0_PWM2A_OUT, 0);
#endif
#ifdef BSP_USING_PWM2B
            PORT_Init(PORTN, PIN6, FUNMUX0_PWM2B_OUT, 0);
#endif
        }
        else if (pwm_obj[i].pwm_cfg->PWMx == PWM3)
        {
#ifdef BSP_USING_PWM3A
            PORT_Init(PORTN, PIN3, FUNMUX1_PWM3A_OUT, 0);
#endif
#ifdef BSP_USING_PWM3B
            PORT_Init(PORTN, PIN5, FUNMUX1_PWM3B_OUT, 0);
#endif
        }
        else if (pwm_obj[i].pwm_cfg->PWMx == PWM4)
        {
#ifdef BSP_USING_PWM4A
            PORT_Init(PORTN, PIN8, FUNMUX0_PWM4A_OUT, 0);
#endif
#ifdef BSP_USING_PWM4B
            PORT_Init(PORTN, PIN10, FUNMUX0_PWM4B_OUT, 0);
#endif
        }
        else if (pwm_obj[i].pwm_cfg->PWMx == PWM5)
        {
#ifdef BSP_USING_PWM5A
            PORT_Init(PORTN, PIN7, FUNMUX1_PWM5A_OUT, 0);
#endif
#ifdef BSP_USING_PWM5B
            PORT_Init(PORTN, PIN9, FUNMUX1_PWM5B_OUT, 0);
#endif
        }

        PWM_Init(pwm_obj[i].pwm_cfg->PWMx, &(pwm_obj[i].pwm_cfg->pwm_initstruct));
        result = rt_device_pwm_register(&pwm_obj[i].pwm_device, pwm_obj[i].pwm_cfg->name, &pwm_ops, pwm_obj[i].pwm_cfg);
        if(result != RT_EOK)
        {
            LOG_E("%s register fail.", pwm_obj[i].pwm_cfg->name);
        }
        else
        {
            LOG_D("%s register success.", pwm_obj[i].pwm_cfg->name);
        }
    }
    return result;
}
INIT_DEVICE_EXPORT(swm_pwm_init);

#endif /* BSP_USING_PWM */
#endif /* RT_USING_PWM */
