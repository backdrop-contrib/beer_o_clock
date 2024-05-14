<?php

/**
 * @file
 * Provides the administration settings for Beer O'Clock.
 */

/**
 * Form builder for Beer O'Clock settings.
 */
function beer_o_clock_settings($form, &$form_state) {
  $config = config('beer_o_clock.settings');

  $form['beer_o_clock_day'] = array(
    '#type' => 'select',
    '#title' => t("Beer O'Clock Day of the week"),
    '#description' => t("The day on which Beer O'Clock is on"),
    '#options' => array(
      0 => t('Sunday'),
      1 => t('Monday'),
      2 => t('Tuesday'),
      3 => t('Wednesday'),
      4 => t('Thursday'),
      5 => t('Friday'),
      6 => t('Saturday'),
    ),
    '#default_value' => $config->get('beer_o_clock_day'),
    '#required' => TRUE,
  );

  $form['beer_o_clock_hour'] = array(
    '#type' => 'select',
    '#title' => t("Beer O'Clock Hour of the day"),
    '#description' => t("The time that Beer O'Clock starts - in 24 hour time format"),
    '#options' => range(0, 23),
    '#default_value' => $config->get('beer_o_clock_hour'),
    '#required' => TRUE,
  );

  $form['beer_o_clock_message'] = array(
    '#title' => t("Message to display when it is Beer O'Clock"),
    '#type' => 'textarea',
    '#description' => t("You can use most common HTML tags"),
    '#default_value' => $config->get('beer_o_clock_message'),
  );

  $form['beer_o_clock_not_message'] = array(
    '#title' => t("Message to display when it is not Beer O'Clock"),
    '#type' => 'textarea',
    '#description' => t("You can use most common HTML tags"),
    '#default_value' => $config->get('beer_o_clock_not_message'),
  );

  $form['beer_o_clock_block_countdown'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display the countdown to Beer O'Clock"),
    '#default_value' => $config->get('beer_o_clock_block_countdown'),
  );

  $form['#submit'][] = 'beer_o_clock_settings_submit';

  return system_settings_form($form);
}

/**
 * Form submit handler for Beer O'Clock settings.
 */
function beer_o_clock_settings_submit($form, &$form_state) {
  $config = config('beer_o_clock.settings');
  $config->set('beer_o_clock_day', $form_state['values']['beer_o_clock_day']);
  $config->set('beer_o_clock_hour', $form_state['values']['beer_o_clock_hour']);
  $config->set('beer_o_clock_message', $form_state['values']['beer_o_clock_message']);
  $config->set('beer_o_clock_not_message', $form_state['values']['beer_o_clock_not_message']);
  $config->set('beer_o_clock_block_countdown', $form_state['values']['beer_o_clock_block_countdown']);
  $config->save();
}
